#include "../term/term.h"
#include "../../lab5/Containers/MyVector.h"

class Polynomial {
private:
	MyVector<Term> poly;
	int degree;
	bool reversed = false;
public:
	explicit Polynomial(const Term&);
	Polynomial(int ratio = 0, int grade = 0) : Polynomial(Term(ratio, grade)) {};

	Polynomial& operator = (Polynomial&);
	Polynomial& operator += (Polynomial&);
	Polynomial& operator *= (Polynomial&);
	void sortPolynomial();
	void reverseSortPolynomial();
	friend std::ostream& operator << (std::ostream&, Polynomial&);
	friend std::istream& operator >> (std::istream&, Polynomial&);
};