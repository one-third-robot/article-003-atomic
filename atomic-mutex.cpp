#include <atomic>
#include <ctime>
#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <vector>

class Test {
public:
    Test( double a, float b, double c ) {
        this->a    = a;
        this->b[0] = b;
        this->c.push_back( c );
    };
    double                a;
    float                 b[100];
    std::vector< double > c;

    std::mutex mutex;
};

std::atomic< Test* > msg;

void threadFunc() {
    for ( int i = 0; i < 2000; i++ ) {
        usleep( 1 );
        Test* n = msg.load( std::memory_order_relaxed );
        n->mutex.lock();
        n->a++;
        n->c.push_back( i );
        n->mutex.unlock();
        msg.store( n, std::memory_order_relaxed );
    }
}

int main( int argc, char* argv[] ) {
    msg = new Test( 0, 0, 0 );
    std::thread th1( threadFunc );
    std::thread th2( threadFunc );
    th1.join();
    th2.join();
    Test* n = msg.load( std::memory_order_relaxed );
    std::cout << "msg->a: " << n->a << "\n"
              << "msg->b[0]: " << n->b[0] << "\n"
              << "msg->c.size(): " << n->c.size() << "\n";
}
