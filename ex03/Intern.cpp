#include "Intern.hpp"

const char *Intern::WrongFormException::what( void ) const throw() {
	return "Wrong Form type";
}

Intern::Intern( void ) {}
Intern::Intern( const Intern &ref ) { *this = ref; }
Intern &Intern::operator=( const Intern &ref ) {
	if ( this != &ref ) {
	}
	return *this;
}
Intern::~Intern( void ) {}

Form *Intern::makeForm( const std::string &form, const std::string &target ) {
	static const std::string forms[3] = {
		"presidential pardon", "robotomy request", "shrubbery creation" };
	static Form *( Intern::*formFunc[3] )( const std::string & ) = {
		&Intern::presidential, &Intern::robotomy, &Intern::shrubbery };
	std::string tmp;
	for ( unsigned long i = 0; i < form.size(); i++ )
		tmp += tolower( form.c_str()[i] );

	int i = 0;
	while ( i < 3 && tmp.compare( forms[i] ) ) i++;
	if ( i == 3 )
		throw WrongFormException();
	std::cout << "Intern creats " << form << std::endl;
	return ( this->*formFunc[i] )( target );
}

Form *Intern::presidential( const std::string &target ) {
	return new PresidentialPardonForm( target );
}
Form *Intern::robotomy( const std::string &target ) {
	return new RobotomyRequestForm( target );
}
Form *Intern::shrubbery( const std::string &target ) {
	return new ShrubberyCreationForm( target );
}