#pragma once

#include "Form.hpp"

class RobotomyRequestForm : public Form {
   private:
	std::string target;
	static const int reqSignGradeRR = 72;
	static const int reqExecGradeRR = 45;

   public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( const RobotomyRequestForm& ref );
	RobotomyRequestForm& operator=( const RobotomyRequestForm& ref );
	virtual ~RobotomyRequestForm( void );

	virtual void execute( Bureaucrat const& b ) const;
};