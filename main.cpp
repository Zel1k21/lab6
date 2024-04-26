#include "polynomial/polynomial.h"

int main()
{
	Term A(-3, 2), B(7, 2), C;
	//std::cin >> C;
	//std::cout << C;

	Polynomial F(4,3), G(2,3), E;	
	std::cin >> E;
	E.sortPolynomial();
	std::cout << E << std::endl;
	E.reverseSortPolynomial();
	std::cout << E;
}