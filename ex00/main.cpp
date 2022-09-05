#include "Bureaucrat.hpp"

int main( void ) {
	{
		std::cout << "+++ Grade is too low test +++" << std::endl;
		try {
			Bureaucrat a( "a", 160 );
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "+++ Grade is too high test +++" << std::endl;
		try {
			Bureaucrat a( "a", 0 );
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "+++ Grade is too low test(unsigned) +++" << std::endl;
		try {
			Bureaucrat a( "a", -1 );
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "+++ increment/decrement grade test +++" << std::endl;
		try {
			Bureaucrat a( "a", 10 );
			a.decrementGrade();
			a.decrementGrade();
			a.incrementGrade();
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "+++ Grade is too high test(incrementGrade) +++"
				  << std::endl;
		try {
			Bureaucrat a( "a", 1 );
			a.incrementGrade();
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "+++ Grade is too low test(decrementGrade) +++"
				  << std::endl;
		try {
			Bureaucrat a( "a", 149 );
			try {
				a.decrementGrade();
				a.decrementGrade();
			} catch ( const std::exception& e ) {
				std::cerr << e.what() << std::endl;
			}
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	// { Bureaucrat a( "a", 0 ); }
}
