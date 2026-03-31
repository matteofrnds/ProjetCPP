
#include "GameManager.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

GameManager::GameManager()

: rng(std::random_device{}())
{
}

static std::string trimLower(std::string s)
{
	auto isSpace = [](unsigned char c) { return std::isspace(c) != 0; };
	while (!s.empty() && isSpace(static_cast<unsigned char>(s.front())))
	{
		s.erase(s.begin());
	}
	while (!s.empty() && isSpace(static_cast<unsigned char>(s.back())))
	{
		s.pop_back();
	}
	for (char& c : s)
	{
		c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
	}
	return s;
}

void GameManager::startGame(PrestigeManager& prestigeManager)
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << std::endl;
	std::cout << "==============================" << std::endl;
	std::cout << "Mode Calcul Mental" << std::endl;
	std::cout << "Bonne reponse => +prestige" << std::endl;
	std::cout << "Tape 'q' / 'quit' pour quitter" << std::endl;

	while (true)
	{
		const Problem p = Problem::generate(rng);
		const int correctAnswer = p.getAnswer();

		std::vector<int> choices;
		choices.reserve(3);
		choices.push_back(correctAnswer);
		std::uniform_int_distribution<int> offsetDist(-20, 20);
		int attempts = 0;
		while (choices.size() < 3)
		{
			int candidate = correctAnswer + offsetDist(rng);
			if (candidate < 0)
			{
				++attempts;
				if (attempts > 200)
				{
					candidate = correctAnswer + static_cast<int>(choices.size()) + 1;
				}
				else
				{
					continue;
				}
			}
			if (candidate == correctAnswer)
			{
				++attempts;
				continue;
			}
			if (std::find(choices.begin(), choices.end(), candidate) != choices.end())
			{
				++attempts;
				continue;
			}
			choices.push_back(candidate);
		}
		std::shuffle(choices.begin(), choices.end(), rng);

		std::cout << std::endl;
		std::cout << p.getText() << " = ?" << std::endl;
		for (size_t i = 0; i < choices.size(); ++i)
		{
			std::cout << (i + 1) << ") " << choices[i] << std::endl;
		}
		std::cout << "Votre choix (1/2/3, ou q) : ";

		std::string input;
		if (!std::getline(std::cin, input))
		{
			return; // EOF
		}

		input = trimLower(input);
		if (input == "q" || input == "quit")
		{
			return;
		}

		int choice = 0;
		std::istringstream iss(input);
		if (!(iss >> choice) || choice < 1 || choice > 3)
		{
			std::cout << "Entree invalide (attendu: 1, 2 ou 3) -> nouveau calcul." << std::endl;
			continue;
		}

		const int selectedValue = choices[static_cast<size_t>(choice - 1)];

		if (selectedValue == correctAnswer)
		{
			std::cout << "Bonne reponse !" << std::endl;
			prestigeManager.prestige();
		}
		else
		{
			std::cout << "Faux (attendu: " << correctAnswer << ") -> nouveau calcul." << std::endl;
		}
	}
}

