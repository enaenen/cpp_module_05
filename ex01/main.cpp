#include "Bureaucrat.hpp"

int main( void ) {
	{
		std::cout << "========== Grade is too HIGH TEST =========="
				  << std::endl;
		try {
			Form topSecert( "Secrect", 0, 0 );
			Form confidentiality( "Confidentiality", 150, 150 );
			std::cout << "Secret and Confidentiality Created" << std::endl;
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "========== Grade is too LOW TEST ==========" << std::endl;
		try {
			Form nothing( "JustPaper", 151, 151 );
			std::cout << "Nothing Form Created" << std::endl;
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "========== Form & Signing TEST ==========" << std::endl;
		try {
			Bureaucrat a( "a", 1 );
			Bureaucrat b( "b", 150 );
			Form secret( "TopGradeSecret", 1, 1 );
			Form paper( "JustPaper", 150, 150 );

			std::cout << secret << std::endl;
			std::cout << paper << std::endl;

			a.signForm( secret );
			std::cout << "Sign is Done" << std::endl;
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "========== Form & Signing DUPLICATE SIGN TEST =========="
				  << std::endl;
		try {
			Bureaucrat a( "a", 1 );
			Bureaucrat b( "b", 150 );
			Form secret( "TopGradeSecret", 1, 1 );
			Form paper( "JustPaper", 150, 150 );

			std::cout << paper << std::endl;

			a.signForm( paper );
			a.signForm( paper );

			std::cout << "Sign is Done" << std::endl;
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "========== Form & Signing FAIL TEST =========="
				  << std::endl;
		try {
			Bureaucrat a( "a", 1 );
			Bureaucrat b( "b", 150 );
			Form secret( "TopGradeSecret", 1, 1 );
			Form paper( "JustPaper", 150, 150 );

			std::cout << paper << std::endl;

			b.signForm( paper );
			b.signForm( secret );

			std::cout << "Sign is Done" << std::endl;
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}
