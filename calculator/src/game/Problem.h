#pragma once

#include <random>
#include <string>

class Problem
{
public:
	Problem() = default;
	Problem(std::string text, int answer);

	const std::string& getText() const { return text; }
	int getAnswer() const { return answer; }

	static Problem generate(std::mt19937& rng);

private:
	std::string text;
	int answer = 0;
};
