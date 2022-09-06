#include "Form.hpp"

const char *Form::GradeTooHighException::what( void ) const throw() {
	return "Grade is too HIGH";
}
const char *Form::GradeTooLowException::what( void ) const throw() {
	return "Grade is too LOW";
}

Form::Form( void )
	: name( "UnNamed" ),
	  signFlag( false ),
	  signGrade( LOWEST ),
	  executeGrade( LOWEST ) {}
Form::Form( std::string name, int signGrade, int executeGrade )
	: name( name ),
	  signFlag( false ),
	  signGrade( signGrade ),
	  executeGrade( executeGrade ) {}
Form::Form( Form const &ref )
	: name( ref.name ),
	  signFlag( ref.signFlag ),
	  signGrade( ref.signGrade ),
	  executeGrade( ref.executeGrade ) {}
Form &Form::operator=( Form const &ref ) {
	if ( this != &ref ) {
		const_cast<std::string &>( name ) = ref.name;
		signFlag = ref.signFlag;
		const_cast<int &>( signGrade ) = ref.signGrade;
		const_cast<int &>( executeGrade ) = ref.executeGrade;
	}
	return *this;
}
Form::~Form( void ) { std::cout << "Form Delete " << std::endl; }

const std::string &Form::getName( void ) const { return name; }
bool Form::isSigned( void ) const { return signFlag; }
int Form::getSigneGrade( void ) const { return signGrade; }
int Form::getExecuteGrade( void ) const { return executeGrade; }
void Form::beSigned( const Bureaucrat &b ) {
	if ( b.getGrade() <= signGrade )
		signFlag = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<( std::ostream &os, Form const &f ) {
	os << "name: " << f.getName() << std::endl;
	os << "isSigned: " << f.isSigned() << std::endl;
	os << "signGrade: " << f.getSigneGrade() << std::endl;
	os << "executeGrade: " << f.getExecuteGrade() << std::endl;
	return os;
}