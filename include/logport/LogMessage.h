#pragma once

#include <string>
using std::string;


namespace logport{
	

	class LogMessage{


		public:
			LogMessage( const string& message );
			const string& getMessage() const;



		protected:
			string message;




	};



}