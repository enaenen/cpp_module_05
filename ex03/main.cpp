#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main( void ) {
	{
		std::cout << "PresidentialPardonFormTest ========================"
				  << std::endl;
		Intern someRandomIntern;
		Form *rrf;
		Bureaucrat admin( "ADMIN", 1 );
		Bureaucrat nobody( "NOBODY", 150 );
		try {
			rrf = someRandomIntern.makeForm( "Presidential Pardon", "Bender" );
			std::cout << "===============EXPECTED FAIL" << std::endl;
			nobody.signForm( *rrf );
			admin.executeForm( *rrf );
			std::cout << "===============EXPECTED SUCCESS" << std::endl;
			admin.signForm( *rrf );
			admin.executeForm( *rrf );
		} catch ( const std::exception &e ) {
			rrf = NULL;
			std::cerr << e.what() << std::endl;

			if ( rrf )
				delete rrf;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "<<Wrong Form Test>> ========================"
				  << std::endl;
		Intern someRandomIntern;
		Form *rrf;
		Bureaucrat admin( "ADMIN", 1 );
		Bureaucrat nobody( "NOBODY", 150 );
		try {
			rrf = someRandomIntern.makeForm( "Presidential", "Bender" );
			std::cout << "===============EXPECTED FAIL" << std::endl;
			nobody.signForm( *rrf );
			admin.executeForm( *rrf );
			std::cout << "===============EXPECTED SUCCESS" << std::endl;
			admin.signForm( *rrf );
			admin.executeForm( *rrf );
		} catch ( const std::exception &e ) {
			rrf = NULL;
			std::cerr << e.what() << std::endl;

			if ( rrf )
				delete rrf;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "RobotomyRequestFormTest ========================"
				  << std::endl;
		Intern someRandomIntern;
		Form *rrf;
		Bureaucrat admin( "ADMIN", 1 );
		Bureaucrat nobody( "NOBODY", 150 );
		try {
			rrf = someRandomIntern.makeForm( "robotomy request", "Bender" );
			std::cout << "===============EXPECTED FAIL" << std::endl;
			nobody.signForm( *rrf );
			admin.executeForm( *rrf );
			std::cout << "===============EXPECTED SUCCESS" << std::endl;
			admin.signForm( *rrf );
			admin.executeForm( *rrf );
		} catch ( const std::exception &e ) {
			rrf = NULL;
			std::cerr << e.what() << std::endl;

			if ( rrf )
				delete rrf;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "ShrubberyFormTest ========================" << std::endl;
		Intern someRandomIntern;
		Form *rrf;
		Bureaucrat admin( "ADMIN", 1 );
		Bureaucrat nobody( "NOBODY", 150 );
		try {
			rrf = someRandomIntern.makeForm( "shrubbery creation", "Bender" );
			std::cout << "===============EXPECTED FAIL" << std::endl;
			nobody.signForm( *rrf );
			admin.executeForm( *rrf );
			std::cout << "===============EXPECTED SUCCESS" << std::endl;
			admin.signForm( *rrf );
			admin.executeForm( *rrf );
		} catch ( const std::exception &e ) {
			rrf = NULL;
			std::cerr << e.what() << std::endl;

			if ( rrf )
				delete rrf;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}