#include <iostream>
#include <cstring>
#include <ctype.h>
#include <algorithm>

class Polynomial;

class Term {
	friend class Polynomial;
private:
	int ratio;
	int grade;
public:
	Term(int r = 0, int g = 0) : ratio(r), grade(g) {};
	const int getRatio() { return ratio; };
	const int getGrade() { return grade; };
	friend std::ostream& operator << (std::ostream&, const Term&);
	friend Term operator + (const Term&, const Term&);
	friend std::istream& operator >> (std::istream&, Term&);
};
