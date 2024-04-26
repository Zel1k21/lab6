#include "polynomial.h"

const int bufferSize = 1024;

Polynomial::Polynomial(const Term& t)
{
	if (t.ratio != 0)
		this->poly.addElement(t);
	degree = t.grade;
	reversed = false;
}

std::ostream& operator << (std::ostream& out, Polynomial& pol)
{
	const int size = pol.poly.getSize();
	int sign = 1;
	for (int i = 0; i < size; i++) {
		if (pol.poly[i].getRatio() > 0)
			sign = 1;
		else
			sign = -1;
		if (i != size && sign == 1 && i != 0)
			std::cout << " + ";
		else if (i != size && sign == -1)
			std::cout << " - ";
		out << Term(pol.poly[i].getRatio() * sign, pol.poly[i].getGrade());
	}
	return out;
}

Polynomial& Polynomial::operator=(Polynomial& p)
{
	this->poly = p.poly;
	this->degree = p.degree;
	return *this;
}

Polynomial& Polynomial::operator+=(Polynomial& other)
{
	int thisSize = this->poly.getSize(), otherSize = other.poly.getSize();
	bool added = false;
	for (int i = 0; i < otherSize; i++) {
		added = false;
		for (int j = 0; j < thisSize; j++) {
			if (other.poly[i].grade == this->poly[j].grade) {
				this->poly[j].ratio += other.poly[i].ratio;
				added = true;
				continue;
			}
		}
		if (added == false) {
			this->poly.addElement(Term(other.poly[i]));
		}
	}
	this->sortPolynomial();
	return *this;
}

std::istream& operator>>(std::istream& in, Polynomial& p)
{
	char buffer[bufferSize];
	in.getline(buffer, bufferSize);
	int beg = 0, tempRatio, tempGrade;
	for(int index = 0; index < bufferSize && buffer[index] != -52; index++) {
		if (buffer[index] == '+' || buffer[index] == '-' || buffer[index] == 0)
		{
			char* tempLine = new char[index - beg];
			int sign = 1;
			strncpy(tempLine, buffer + beg, index - beg);
			tempLine[index - beg] = '\0';
			char* pch, * pend;
			pch = strchr(tempLine, 'x');
			pend = strchr(tempLine, '^');
			tempRatio = strtol(tempLine, &pch, 10);
			if (buffer[beg - 1] == '-')
				sign = -1;
			if (pend != NULL && tempRatio != 0)
				tempGrade = strtol(pend + 1, NULL, 10);
			else if (tempRatio == 0 && pend != NULL) {
				tempGrade = strtol(pend + 1, NULL, 10);
				tempRatio = 1;
			}
			else 
				tempGrade = 0;
			auto t = Polynomial(tempRatio * sign, tempGrade);
			p += t;
			beg = index + 1;
		}
	}
	p.sortPolynomial();
	return in;
}

Polynomial& Polynomial::operator*=(Polynomial& other)
{
	Polynomial newPol;
	const int thisSize = this->poly.getSize(), const otherSize = other.poly.getSize();
	for (int i = 0; i < thisSize; i++) {
		for (int j = 0; j < otherSize; j++) {
			newPol += Polynomial(this->poly[i].getRatio() * other.poly[j].getRatio(), this->poly[i].getGrade() * other.poly[j].getGrade());
		}
	}
	*this = newPol;
	this->sortPolynomial();
	return *this;
}

void Polynomial::sortPolynomial()
{
	for (int i = 0; i < this->poly.getSize() - 1; i++)
		for (int j = i + 1; j < this->poly.getSize(); j++)
			if (this->poly[i].grade < this->poly[j].grade)
				std::swap(this->poly[i], this->poly[j]);
}

void Polynomial::reverseSortPolynomial()
{
	for (int i = 0; i < this->poly.getSize() - 1; i++)
		for (int j = i + 1; j < this->poly.getSize(); j++)
			if (this->poly[i].grade > this->poly[j].grade)
				std::swap(this->poly[i], this->poly[j]);
	reversed = true;
}