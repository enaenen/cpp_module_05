#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void ) {
	{
		std::cout << "PresidentialPardonFormTest ========================"
				  << std::endl;
		Bureaucrat b1( "a", 5 );
		RobotomyRequestForm aForm( "abcd" );

		b1.signForm( aForm );
		b1.executeForm( aForm );
	}
}
