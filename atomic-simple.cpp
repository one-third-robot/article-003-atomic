#include <atomic>
#include <ctime>
#include <iostream>
#include <thread>
#include <unistd.h>

std::atomic< int > data( 0 );

void threadFunc() {
    for ( int i = 0; i < 2000; i++ ) {
        usleep( 1 );
        data++;
    }
}

int main( int argc, char* argv[] ) {
    std::thread th1( threadFunc );
    std::thread th2( threadFunc );
    th1.join();
    th2.join();
    usleep( 20000 );
    std::cout << "data = " << data << std::endl;
    return 0;
}
