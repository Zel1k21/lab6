#include "term.h"

std::ostream& operator<<(std::ostream& out, const Term& term)
{
	if (term.ratio == 0)
		return out;
	if(term.ratio != 1)
		out << term.ratio;
	if (term.grade != 0) {
		out << 'x';
		if (term.grade != 1)
			out << '^' << term.grade;
	}
	return out;
}

Term operator+(const Term& lhs, const Term& rhs)
{
	Term result;
	if (lhs.grade == rhs.grade) {
		result.grade = lhs.grade;
		result.ratio = lhs.ratio + rhs.ratio;
	}
	return result;
}

std::istream& operator>>(std::istream& in, Term& term)
{
	char* line = new char[20];
	std::cin.getline(line, 20, '\n');
	char* pch, *pend;
	pch = strchr(line, 'x');
	pend = strchr(line, '^');
	term.ratio = strtol(line, &pch, 10);
	term.grade = strtol(pend + 1, NULL, 10);
	delete[] line, pch, pend;
	return in;
}