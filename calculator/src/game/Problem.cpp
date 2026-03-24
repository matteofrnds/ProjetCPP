#include "Problem.h"

#include <utility>

Problem::Problem(std::string text, int answer)
	: text(std::move(text))
	, answer(answer)
{
}

Problem Problem::generate(std::mt19937& rng)
{
	std::uniform_int_distribution<int> aDist(1, 50);
	std::uniform_int_distribution<int> bDist(1, 50);
	std::uniform_int_distribution<int> opDist(0, 2); // +, -, *

	const int a = aDist(rng);
	const int b = bDist(rng);
	const int op = opDist(rng);

	if (op == 0)
	{
		return {std::to_string(a) + " + " + std::to_string(b), a + b};
	}
	if (op == 1)
	{
		const int big = (a >= b) ? a : b;
		const int small = (a >= b) ? b : a;
		return {std::to_string(big) + " - " + std::to_string(small), big - small};
	}

	return {std::to_string(a) + " * " + std::to_string(b), a * b};
}
