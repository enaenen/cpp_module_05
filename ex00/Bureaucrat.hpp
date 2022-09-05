#pragma once

#include <iostream>
#include <exception>

#define LOWEST 150
#define HIGHEST 1

class Bureaucrat {
   private:
	const std::string name;
	int grade;

   public:
	Bureaucrat( void );
	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat &ref );
	Bureaucrat &operator=( const Bureaucrat &ref );
	~Bureaucrat( void );

	class GradeTooHighException : public std::exception {
	   public:
		const char *what( void ) const throw();
	};
	class GradeTooLowException : public std::exception {
	   public:
		const char *what( void ) const throw();
	};

	std::string getName() const;
	int getGrade() const;

	void promoteGrade( void );
	void demoteGrade( void );
};
std::ostream &operator<<( std::ostream &os, const Bureaucrat &b );
