#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: Form( "ShrubberyCreationForm", reqSignGradeSC, reqExecGradeSC ),
	  target( "UnNamedSC" ) {}
ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	: Form( "ShrubberyCreationForm", reqSignGradeSC, reqExecGradeSC ),
	  target( target ) {}
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& ref )
	: Form( ref.getName(), ref.getSigneGrade(), ref.getExecuteGrade() ),
	  target( ref.target ) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm& ref ) {
	if ( this != &ref ) {
		this->setName( ref.getName() );
		this->setSignGrade( ref.getSigneGrade() );
		this->setExecuteGrade( ref.getExecuteGrade() );
		this->setSignFlag( ref.isSigned() );
	}
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

void ShrubberyCreationForm::execute( Bureaucrat const& b ) const {
	executeValidation( b );

	std::ifstream ifs;
	std::ofstream ofs;
	std::string fileName;

	fileName = target + "_shrubbery";
	ifs.open( "ascii_tree.txt" );
	if ( ifs.fail() || ifs.bad() )
		throw Form::FileControlException();
	ofs.open( fileName.c_str() );
	if ( ofs.fail() || ofs.bad() )
		throw Form::FileControlException();
	std::string input;
	while ( true ) {
		std::getline( ifs, input );
		if ( ifs.eof() )
			break;
		ofs << input << std::endl;
	}

	ifs.close();
	ofs.close();
}