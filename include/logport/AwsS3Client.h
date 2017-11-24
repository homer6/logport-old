#pragma once

#include <string>
using std::string;


namespace logport{
	

	class AwsS3Client{


		public:
			AwsS3Client();

			void setBucketName( const string& bucket_name );
			void putFile( const string& file_name, const string& file_contents );


		protected:
			Aws::Client::ClientConfiguration client_config;
			Aws::S3::S3Client s3_client;
			string bucket_name;

	};



}