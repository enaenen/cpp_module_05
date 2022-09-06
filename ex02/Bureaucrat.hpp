#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

#define LOWEST 150
#define HIGHEST 1

class Form;

class Bureaucrat {
   private:
	const std::string name;
	int grade;

   public:
	class GradeTooHighException : public std::exception {
	   public:
		const char *what( void ) const throw();
	};
	class GradeTooLowException : public std::exception {
	   public:
		const char *what( void ) const throw();
	};

	Bureaucrat( void );
	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat &ref );
	Bureaucrat &operator=( const Bureaucrat &ref );
	~Bureaucrat( void );

	std::string getName() const;
	int getGrade() const;

	void promoteGrade( void );
	void demoteGrade( void );

	void signForm( Form &form ) const;
};
std::ostream &operator<<( std::ostream &os, const Bureaucrat &b );
