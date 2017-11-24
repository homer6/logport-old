#include "logport/AwsS3Client.h"

#include <aws/s3/S3Client.h>
#include <aws/s3/model/PutObjectRequest.h>
#include <fstream>


namespace logport{

	AwsS3Client()
		:client_config( Aws::Client::ClientConfiguration() ),
		s3_client( this->client_config )
	{

		   // Aws::Client::ClientConfiguration clientConfig;
    	//if (!region.empty())
   		//   clientConfig.region = region;
    	//Aws::S3::S3Client s3_client(clientConfig);



	}



	void AwsS3Client::setBucketName( const string& bucket_name ){

		this->bucket_name = bucket_name;

	}



	void AwsS3Client::putFile( const string& file_name, const string& file_contents ){

	    Aws::S3::Model::PutObjectRequest object_request;
	    object_request.WithBucket( this->bucket_name.c_str() ).WithKey( file_name.c_str() );
	    auto input_data = Aws::MakeShared<Aws::FStream>( "PutObjectInputStream", file_name.c_str(), std::ios_base::in | std::ios_base::binary );
	    object_request.SetBody("123456");
	    auto put_object_outcome = this->s3_client.PutObject(object_request);

	    if( put_object_outcome.IsSuccess() ){
	        std::cout << "Done!" << std::endl;
	    }else{
	        std::cout << "PutObject error: " <<
	            put_object_outcome.GetError().GetExceptionName() << " " <<
	            put_object_outcome.GetError().GetMessage() << std::endl;
	    }

	}




}
