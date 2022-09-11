#include "Form.hpp"

const char *Form::GradeTooHighException::what( void ) const throw() {
	return "Grade is too HIGH";
}
const char *Form::GradeTooLowException::what( void ) const throw() {
	return "Grade is too LOW";
}
const char *Form::AlreadySignedException::what( void ) const throw() {
	return "Already Signed";
}
const char *Form::NotSignedException::what( void ) const throw() {
	return "Form is not Signed";
}
const char *Form::FileControlException::what( void ) const throw() {
	return "Invalid file";
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
	  executeGrade( executeGrade ) {
	if ( signGrade < HIGHEST || executeGrade < HIGHEST )
		throw GradeTooHighException();
	else if ( LOWEST < signGrade || LOWEST < executeGrade )
		throw GradeTooLowException();
}
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
Form::~Form( void ) {
	// std::cout << "Form Delete " << std::endl;
}

const std::string &Form::getName( void ) const { return name; }
bool Form::isSigned( void ) const { return signFlag; }
int Form::getSigneGrade( void ) const { return signGrade; }
int Form::getExecuteGrade( void ) const { return executeGrade; }

void Form::setName( std::string name ) {
	const_cast<std::string &>( this->name ) = name;
}
void Form::setSignFlag( bool signFlag ) { this->signFlag = signFlag; }
void Form::setSignGrade( int signGrade ) {
	const_cast<int &>( this->signGrade ) = signGrade;
}
void Form::setExecuteGrade( int executeGrade ) {
	const_cast<int &>( this->executeGrade ) = executeGrade;
}

void Form::beSigned( const Bureaucrat &b ) {
	if ( signFlag == true )
		throw AlreadySignedException();
	if ( b.getGrade() <= signGrade )
		signFlag = true;
	else
		throw GradeTooLowException();
}

void Form::executeValidation( Bureaucrat const &b ) const {
	if ( isSigned() == false )
		throw Form::NotSignedException();
	if ( getExecuteGrade() < b.getGrade() )
		throw Form::GradeTooLowException();
}

std::ostream &operator<<( std::ostream &os, Form const &f ) {
	os << "name: " << f.getName() << std::endl;
	os << "isSigned: " << f.isSigned() << std::endl;
	os << "signGrade: " << f.getSigneGrade() << std::endl;
	os << "executeGrade: " << f.getExecuteGrade() << std::endl;
	return os;
}