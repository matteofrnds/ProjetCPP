# Project2026 — Calculator Game (C++)

Application console de calcul mental en C++ (orienté objet). Le programme génère des exercices (+ / − / ×), propose un QCM et suit une progression de type *prestige* (gamification). Une mascotte (“Lapinou”) peut être affichée/masquée et évolue selon le niveau de prestige.

## Pré-requis

- CMake ≥ 3.16

## Compilation

```bash
cmake -S . -B build
cmake --build build -j
```

OU

Lancer le script `start-up.sh`
```bash
./start-up.sh
```

L’exécutable est généré dans `build/calculator/calculator` (selon le générateur/OS).

## Exécution

Depuis la racine du dépôt :

```bash
./build/calculator/calculator
```

## Fonctionnalités

### Fonctionnalité de base (calcul mental)

- L’application pose des questions de calcul mental à l’utilisateur et lui permet d’y répondre via un QCM.

### Fonctionnalités supplémentaires implémentées (3+)

1. **Génération aléatoire de problèmes**
	 - Les exercices sont générés à la volée, de façon pseudo-aléatoire.

2. **Variété d’opérations**
	 - Addition, soustraction (résultat garanti non négatif) et multiplication.

3. **Mode QCM (3 propositions)**
	 - Pour chaque problème, 3 réponses sont proposées (dont la bonne) et sont mélangées.

4. **Robustesse de saisie utilisateur**
	 - Saisie via `getline`, gestion de `q` / `quit` pour quitter, et messages d’erreur en cas d’entrée invalide.

### Mascotte (obligatoire)

- La mascotte “Lapinou” est affichée dans le menu principal.
- Elle peut être **activée/désactivée** depuis le menu.
- Son apparence évolue selon le **niveau de prestige**.

### Gamification (obligatoire)

- **Système de prestige** :
	- Une bonne réponse augmente les *prestige points*.
	- Quand le nombre de points atteint un coût (`prestigeCost`), le *prestige level* augmente et le coût augmente pour le niveau suivant.
	- Un niveau maximum est défini (par défaut 5).

## Utilisation (menu)

Au lancement :

1. **Game Mode** : lance une boucle de calcul mental.
2. **Prestige** : affiche les informations de prestige (niveau, points, coût).
3. **Enable/Disable Lapinou** : affiche/masque la mascotte.
4. **Quit** : quitte le programme.

Dans le mode de jeu :

- Choisir `1`, `2` ou `3` pour répondre.
- Taper `q` ou `quit` pour quitter et revenir au menu.

## Organisation du code

Le code est dans `calculator/src/` et suit une séparation “par domaine” :

- `calculator/src/main.cpp`
	- Point d’entrée, boucle principale, dispatch des actions du menu.

- `calculator/src/menu/`
	- `Menu` : affichage du menu principal (UI console).
	- `Mascotte` : gestion de l’affichage de la mascotte et activation/désactivation.

- `calculator/src/game/`
	- `GameManager` : logique du mode de jeu (boucle de questions, saisie utilisateur, vérification de réponse).
	- `Problem` : représentation d’un exercice (texte + réponse) et génération aléatoire.

- `calculator/src/prestige/`
	- `PrestigeManager` : stockage et évolution des points/niveaux (gamification).

## Séparation des responsabilités (OOP)

- `Menu` ne fait que l’affichage et ne contient pas la logique de jeu.
- `GameManager` gère la logique de jeu et s’appuie sur `Problem` pour générer les exercices.
- `PrestigeManager` encapsule les règles de progression (points, coût, niveau max).
- `Mascotte` est un composant d’UI optionnel et dépend seulement de l’état à afficher (niveau de prestige).

L’objectif est de garder chaque composant avec une responsabilité claire et de limiter les dépendances.