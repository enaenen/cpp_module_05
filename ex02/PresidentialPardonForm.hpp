#pragma once

#include "Form.hpp"

class PresidentailPardonForm : public Form {
   private:
	std::string target;
	static const int reqSignGradePP = 25;
	static const int executeGradePP = 5;

   public:
	PresidentailPardonForm( void );
	PresidentailPardonForm( std::string target );
	PresidentailPardonForm( PresidentailPardonForm const& ref );
	PresidentailPardonForm& operator=( PresidentailPardonForm const& ref );
	virtual ~PresidentailPardonForm( void );

	virtual void execute( Bureaucrat const& b ) const;
};