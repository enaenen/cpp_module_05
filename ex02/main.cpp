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
		PresidentialPardonForm aForm( "PPF_FORM" );

		admin.signForm( aForm );
		admin.executeForm( aForm );
		nobody
	}
}
