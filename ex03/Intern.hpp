#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
   private:
	Form *presidential( const std::string &target );
	Form *robotomy( const std::string &target );
	Form *shrubbery( const std::string &target );

   public:
	class WrongFormException : public std::exception {
	   public:
		const char *what( void ) const throw();
	};

	Intern( void );
	Intern( const Intern &ref );
	Intern &operator=( const Intern &ref );
	~Intern( void );

	Form *makeForm( const std::string &form, const std::string &target );
};
