#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return "[ * EXCEPTION * ] Grade is too HIGH";
}
const char *Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return "[ * EXCEPTION * ] Grade is too LOW";
}

Bureaucrat::Bureaucrat( void ) : name( "UnNamed" ), grade( LOWEST ) {
	// std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}
Bureaucrat::Bureaucrat( std::string name, int grade ) : name( name ) {
	// std::cout << "Bureaucrat (string, int) Constructor Called" << std::endl;
	if ( grade < HIGHEST )
		throw GradeTooHighException();
	else if ( LOWEST < grade )
		throw GradeTooLowException();
	this->grade = grade;
}
Bureaucrat::Bureaucrat( const Bureaucrat &ref ) {
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
	*this = ref;
}
Bureaucrat &Bureaucrat::operator=( const Bureaucrat &ref ) {
	// std::cout << "Bureaucrat Copy Operator Called " << std::endl;
	if ( this != &ref ) {
		const_cast<std::string &>( name ) = ref.name;
		grade = ref.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {
	// std::cout << getName() << " Bureaucrat Destructor Called " << std::endl;
}

std::string Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::promoteGrade( void ) {
	if ( HIGHEST < grade ) {
		std::cout << "[ Promote Grade ]" << name << " " << grade << " to "
				  << grade - 1 << std::endl;
		grade--;
	} else
		throw GradeTooHighException();
}
void Bureaucrat::demoteGrade( void ) {
	if ( grade < LOWEST ) {
		std::cout << "[ Demote Grade ] " << name << " " << grade << " to "
				  << grade + 1 << std::endl;
		grade++;
	} else
		throw GradeTooLowException();
}

void Bureaucrat::signForm( Form &form ) const {
	try {
		form.beSigned( *this );
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch ( std::exception &e ) {
		std::cout << name << " couldn't signed " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm( Form const &form ) const {
	try {
		std::cout << getName() << " executed " << form.getName() << std::endl;
		form.execute( *this );
	} catch ( std::exception &e ) {
		std::cout << getName() << "couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<( std::ostream &os, const Bureaucrat &b ) {
	os << "name : " << b.getName() << std::endl
	   << "Grade : " << b.getGrade() << std::endl;
	return os;
}