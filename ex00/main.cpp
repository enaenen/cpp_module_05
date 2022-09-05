#include "Bureaucrat.hpp"

int main( void ) {
	{
		std::cout << "========== Grade is too low test (Constructer) =========="
				  << std::endl;
		try {
			Bureaucrat a( "a", 160 );
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout
			<< "========== Grade is too High test(-1) (Constructer)=========="
			<< std::endl;
		try {
			Bureaucrat a( "a", -1 );
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "========== Promote/DemoteGrade() test =========="
				  << std::endl;
		try {
			Bureaucrat a( "a", 1 );
			std::cout << "Before demote : " << a.getGrade() << std::endl;
			a.demoteGrade();
			a.demoteGrade();
			a.demoteGrade();
			std::cout << "After demote : " << a.getGrade() << std::endl;
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout
			<< "========== Grade is too high test(Promote Grade) =========="
			<< std::endl;
		try {
			Bureaucrat a( "a", 1 );
			a.promoteGrade();
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "========== Grade is too low test(Demote Grade) =========="
				  << std::endl;
		try {
			Bureaucrat a( "a", 149 );
			try {
				a.demoteGrade();
				a.demoteGrade();
			} catch ( const std::exception& e ) {
				std::cerr << e.what() << std::endl;
			}
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}
