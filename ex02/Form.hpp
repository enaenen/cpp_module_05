#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
   private:
	const std::string name;
	bool signFlag;
	const int signGrade;
	const int executeGrade;

   public:
	class GradeTooHighException : public std::exception {
	   public:
		const char *what( void ) const throw();
	};
	class GradeTooLowException : public std::exception {
	   public:
		const char *what( void ) const throw();
	};
	class AlreadySignedException : public std::exception {
	   public:
		const char *what( void ) const throw();
	};
	class NotSignedException : public std::exception {
	   public:
		const char *what( void ) const throw();
	};

	Form( void );
	Form( std::string name, int signGrade, int executeGrade );
	Form( Form const &ref );
	Form &operator=( Form const &ref );
	virtual ~Form( void );

	const std::string &getName( void ) const;
	bool isSigned( void ) const;
	int getSigneGrade( void ) const;
	int getExecuteGrade( void ) const;
	void setName( std::string name );
	void setSignFlag( bool signFlag );
	void setSignGrade( int signGrade );
	void setExecuteGrade( int executeGrade );

	void beSigned( const Bureaucrat &b );
	virtual void execute( Bureaucrat const &executor ) const = 0;
	void executeValidation( Bureaucrat const &b ) const;
};
std::ostream &operator<<( std::ostream &os, Form const &f );