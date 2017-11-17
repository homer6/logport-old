#include <cppkafka/producer.h>
#include <iostream>
#include <string>

using namespace cppkafka;

using std::string;
using std::cout;
using std::cin;
using std::endl;


int main( int argc, char **argv ){

    string broker_address;
    string topic_name;

    if( argc != 3 ){
        cout << "Usage: " << argv[0] << " <broker> <kafka-topic-name>" << endl;
        cout << "Eg1: " << argv[0] <<   " 127.0.0.1:9092 my-topic" << endl;
        cout << "Eg2: " << argv[0] <<   " 127.0.0.1:9092,192.168.0.1:9092 my-topic" << endl;
        return 0;
    }else{
        topic_name = string( argv[2] );
        broker_address = string( argv[1] );
    }

    // Create the config
    Configuration config = {
        { "metadata.broker.list", broker_address }
    };

    // Create the producer
    Producer producer(config);

    for( string line; std::getline(std::cin, line); ){
        producer.produce( MessageBuilder(topic_name).partition(0).payload(line) );
    }

    return 0;

}
