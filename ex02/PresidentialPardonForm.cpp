#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
	: Form( "PresidentialPardonForm", reqSignGradePP, reqExecGradePP ),
	  target( "UnNamedPP" ) {}
PresidentialPardonForm::PresidentialPardonForm( std::string target )
	: Form( "PresidentialPardonForm", reqSignGradePP, reqExecGradePP ),
	  target( target ) {}
PresidentialPardonForm::PresidentialPardonForm(
	PresidentialPardonForm const& ref )
	: Form( ref.getName(), ref.getSigneGrade(), ref.getExecuteGrade() ) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(
	PresidentialPardonForm const& ref ) {
	if ( this != &ref ) {
		this->setName( ref.getName() );
		this->setSignGrade( ref.getSigneGrade() );
		this->setExecuteGrade( ref.getExecuteGrade() );
		this->setSignFlag( ref.isSigned() );
	}
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm( void ) {}

void PresidentialPardonForm::execute( Bureaucrat const& b ) const {
	executeValidation( b );
	std::cout << target << " has been pardoned by Zaphod Beeblebrox."
			  << std::endl;
}
