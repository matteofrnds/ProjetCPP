
#include "GameManager.h"

#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>

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
		std::cout << std::endl;
		std::cout << p.getText() << " = ";

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

		int value = 0;
		std::istringstream iss(input);
		if (!(iss >> value))
		{
			std::cout << "Entree invalide -> nouveau calcul." << std::endl;
			continue;
		}

		if (value == p.getAnswer())
		{
			std::cout << "Bonne reponse !" << std::endl;
			prestigeManager.prestige();
		}
		else
		{
			std::cout << "Faux (attendu: " << p.getAnswer() << ") -> nouveau calcul." << std::endl;
		}
	}
}

