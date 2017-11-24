#include <cppkafka/producer.h>
#include <iostream>
#include <string>

using namespace cppkafka;

using std::string;
using std::cout;
using std::cin;
using std::endl;

#include <aws/core/Aws.h>



int main( int argc, char **argv ){

    string broker_address;
    string topic_name;
    string bucket_name;

    if( argc != 4 ){
        cout << "Usage: " << argv[0] << " <broker> <kafka-topic-name> <s3-bucket-name>" << endl;
        cout << "Eg1: " << argv[0] <<   " 127.0.0.1:9092 my-topic my-bucket" << endl;
        cout << "Eg2: " << argv[0] <<   " 127.0.0.1:9092,192.168.0.1:9092 my-topic my-bucket" << endl;
        return 0;
    }else{
        broker_address = string( argv[1] );
        topic_name = string( argv[2] );
        bucket_name = string( argv[3] );
    }

    // Create the config
    cppkafka::Configuration config = {
        { "metadata.broker.list", broker_address }
    };

    // Create the producer
    cppkafka::Producer producer(config);

    Aws::SDKOptions options;
    Aws::InitAPI(options);





    /*
    for( string line; std::getline(std::cin, line); ){
        cout << line << endl;
        //producer.produce( MessageBuilder(topic_name).partition(0).payload(line) );
    }*/



    Aws::ShutdownAPI(options);


    return 0;

}
