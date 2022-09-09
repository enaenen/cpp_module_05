#pragma once

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
   private:
	std::string target;
	static const int reqSignGradeSC = 145;
	static const int reqExecGradeSC = 137;

   public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm& ref );
	ShrubberyCreationForm& operator=( const ShrubberyCreationForm& ref );
	virtual ~ShrubberyCreationForm( void );

	virtual void execute( Bureaucrat const& b );
};