#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <sys/time.h>

RobotomyRequestForm::RobotomyRequestForm( void )
	: Form( "RobotomyRequestForm", reqSignGradeRR, reqExecGradeRR ),
	  target( "UnNamedRR" ) {}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: Form( "RobotomyRequestForm", reqSignGradeRR, reqExecGradeRR ),
	  target( target ) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& ref )
	: Form( ref.getName(), ref.getSigneGrade(), ref.getExecuteGrade() ) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
	const RobotomyRequestForm& ref ) {
	if ( this != &ref ) {
		this->setName( ref.getName() );
		this->setSignGrade( ref.getSigneGrade() );
		this->setExecuteGrade( ref.getExecuteGrade() );
		this->setSignFlag( ref.isSigned() );
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

void RobotomyRequestForm::execute( Bureaucrat const& b ) const {
	executeValidation( b );
	struct timeval t;
	gettimeofday( &t, NULL );
	srand( t.tv_usec );
	int random = rand();
	std::cout << "**Driling noise**" << std::endl;
	if ( random % 2 == 0 )
		std::cout << target << " has been robotomized" << std::endl;
	else
		std::cout << target << " has been faild to robotomized." << std::endl;
}