#pragma once

#include <iostream>

class Breaucrat {
   private:
	const std::string name;
	int grade;

   public:
	Breaucrat( std::string name, int grade );
	~Breaucrat();
	int getName();
	int getGrade();
};
