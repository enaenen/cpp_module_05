#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void ) {
	{
		std::cout << "PresidentialPardonFormTest ========================"
				  << std::endl;
		Bureaucrat admin( "ADMIN", 1 );
		Bureaucrat b1( "a", 5 );
		Bureaucrat nobody( "NOBODY", 150 );
		PresidentialPardonForm aForm( "AFORM" );
		PresidentialPardonForm bForm( "BFORM" );

		admin.signForm( aForm );
		admin.executeForm( aForm );
		std::cout << "===============EXPECTED FAIL" << std::endl;
		nobody.executeForm( aForm );
		nobody.signForm( aForm );
		nobody.executeForm( bForm );
		nobody.signForm( bForm );
		admin.executeForm( bForm );
	}
	{
		std::cout << "RobotomyRequestFormTest ========================"
				  << std::endl;
		Bureaucrat admin( "ADMIN", 1 );
		Bureaucrat b1( "a", 5 );
		Bureaucrat nobody( "NOBODY", 150 );
		RobotomyRequestForm aForm( "RRF_AFORM" );
		RobotomyRequestForm bForm( "RRF_BFORM" );

		admin.signForm( aForm );
		admin.executeForm( aForm );
		admin.executeForm( aForm );
		admin.executeForm( aForm );
		std::cout << "===============EXPECTED FAIL" << std::endl;
		nobody.executeForm( aForm );
		nobody.signForm( aForm );
		nobody.executeForm( bForm );
		nobody.signForm( bForm );
		admin.executeForm( bForm );
	}

	{
		std::cout << "ShrubberyCreationFormTest ========================"
				  << std::endl;
		Bureaucrat admin( "ADMIN", 1 );
		Bureaucrat b1( "a", 5 );
		Bureaucrat nobody( "NOBODY", 150 );
		Bureaucrat middle( "MIDDLEMAN", 100 );

		ShrubberyCreationForm aForm( "SCF_AFORM" );
		ShrubberyCreationForm bForm( "SCF_BFORM" );
		ShrubberyCreationForm cForm( "SCF_CFORM" );

		admin.signForm( aForm );
		admin.executeForm( aForm );
		admin.signForm( cForm );
		middle.executeForm( cForm );
		std::cout << "===============EXPECTED FAIL" << std::endl;
		nobody.signForm( bForm );
		nobody.executeForm( aForm );
		nobody.signForm( aForm );
		nobody.executeForm( bForm );
		nobody.signForm( bForm );
		admin.executeForm( bForm );
	}
}
