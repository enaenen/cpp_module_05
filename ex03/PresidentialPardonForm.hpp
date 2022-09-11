#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form {
   private:
	std::string target;
	static const int reqSignGradePP = 25;
	static const int reqExecGradePP = 5;

   public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( PresidentialPardonForm const& ref );
	PresidentialPardonForm& operator=( PresidentialPardonForm const& ref );
	virtual ~PresidentialPardonForm( void );

	virtual void execute( Bureaucrat const& b ) const;
};