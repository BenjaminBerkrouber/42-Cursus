# Libft: Votre première bibliothèque en C

> Projet réalisé dans le cadre de la formation à l'école 42

## Sommaire

- [Introduction](#introduction)
- [Objectifs](#objectifs)
- [Instructions Générales](#instructions-générales)
- [Fonctions Implémentées](#fonctions-implémentées)

## Introduction

Le projet `libft` consiste à créer une bibliothèque de fonctions utilitaires en C qui pourront être réutilisées dans la plupart de vos projets C tout au long de l'année. Cela vous permettra de gagner un temps précieux. Voir le projet `libft` comme un rappel de la phase de bootcamp et utilisez-le judicieusement pour évaluer votre niveau et vos progrès.

## Objectifs

La programmation en C peut être très fastidieuse lorsqu'on n'a pas accès à ces fonctions standard très utiles. Ce projet vous permet de prendre le temps de réécrire ces fonctions, de les comprendre et de les apprendre à utiliser. Cette bibliothèque vous aidera pour tous vos futurs projets en C.

## Instructions Générales

- Le projet doit être écrit conformément à la Norme.
- Aucun comportement indéfini n'est autorisé pour les fonctions.
- Vous devez soumettre un fichier `Makefile` pour compiler votre bibliothèque en une librairie statique `libft.a`.

## Fonctions Implémentées

### Libft functions

| Fonction         | Description                        | Statut                        |
| ---------------- | ---------------------------------- | ----------------------------- |
| [`memset`](#)    | Remplit une zone mémoire            | ✅                            |
| [`bzero`](#)     | Met à zéro une zone mémoire         | ✅                            |
| [`memcpy`](#)    | Copie de la mémoire                 | ✅                            |
| [`memccpy`](#)   | Copie conditionnelle de la mémoire  | ❌                            |
| [`memmove`](#)   | Déplace de la mémoire               | ❌                            |
| [`memchr`](#)    | Recherche dans la mémoire           | ❌                            |
| [`memcmp`](#)    | Compare de la mémoire               | ❌                            |
| [`strlen`](#)    | Calcule la longueur d'une chaîne    | ✅                            |
| [`strdup`](#)    | Duplique une chaîne                 | ✅                            |
| [`strcpy`](#)    | Copie une chaîne                    | ✅                            |
| [`strncpy`](#)   | Copie limitée d'une chaîne          | ✅                            |
| [`strcat`](#)    | Concaténation de chaînes            | ✅                            |
| [`strncat`](#)   | Concaténation limitée de chaînes    | ✅                            |
| [`strlcat`](#)   | Concaténation sécurisée de chaînes  | ❌                            |
| [`strchr`](#)    | Recherche d'un caractère            | ✅                            |
| [`strrchr`](#)   | Recherche inversée d'un caractère   | ✅                            |
| [`strstr`](#)    | Recherche d'une sous-chaîne         | ✅                            |
| [`strnstr`](#)   | Recherche limitée d'une sous-chaîne | ✅                            |
| [`strcmp`](#)    | Compare deux chaînes                | ✅                            |
| [`strncmp`](#)   | Compare limitée de chaînes          | ✅                            |
| [`atoi`](#)      | Conversion chaîne à entier          | ✅                            |
| [`isalpha`](#)   | Teste si alphabétique               | ✅                            |
| [`isdigit`](#)   | Teste si numérique                  | ✅                            |
| [`isalnum`](#)   | Teste si alphanumérique             | ✅                            |
| [`isascii`](#)   | Teste si ASCII                      | ✅                            |
| [`isprint`](#)   | Teste si imprimable                 | ✅                            |
| [`toupper`](#)   | Convertit en majuscule              | ✅                            |
| [`tolower`](#)   | Convertit en minuscule              | ✅                            |

✅ = Fonction réalisée
❌ = Fonction non réalisée

### Additional functions

| Fonction                    | Description                                        | Statut                        |
| --------------------------- | -------------------------------------------------- | ----------------------------- |
| [`ft_memalloc`](#)          | Alloue et initialise une zone mémoire à zéro.      | ✅                            |
| [`ft_memdel`](#)            | Libère une zone mémoire et met le pointeur à NULL. | ✅                            |
| [`ft_strnew`](#)            | Alloue et retourne une nouvelle chaîne terminée par un '\0'. | ✅                  |
| [`ft_strdel`](#)            | Libère une chaîne et met le pointeur à NULL.       | ✅  a check                          |
| [`ft_strclr`](#)            | Réinitialise chaque caractère de la chaîne à '\0'. | ✅                            |
| [`ft_striter`](#)           | Applique une fonction à chaque caractère d'une chaîne. | ❌                        |
| [`ft_striteri`](#)          | Applique une fonction à chaque caractère d'une chaîne avec index. | ❌                 |
| [`ft_strmap`](#)            | Crée une nouvelle chaîne en appliquant une fonction à chaque caractère. | ❌             |
| [`ft_strmapi`](#)           | Crée une nouvelle chaîne en appliquant une fonction à chaque caractère avec index. | ❌  |
| [`ft_strequ`](#)            | Compare lexicographiquement deux chaînes.          | ❌                            |
| [`ft_strnequ`](#)           | Compare lexicographiquement deux chaînes jusqu'à n caractères. | ❌                    |
| [`ft_strsub`](#)            | Crée une nouvelle sous-chaîne.                     | ❌                            |
| [`ft_strjoin`](#)           | Concatène deux chaînes.                            | ❌                            |
| [`ft_strtrim`](#)           | Supprime les espaces blancs au début et à la fin.  | ❌                            |
| [`ft_strsplit`](#)          | Divise une chaîne en un tableau.                   | ❌                            |
| [`ft_itoa`](#)              | Convertit un entier en une nouvelle chaîne.        | ❌                            |
| [`ft_putchar`](#)           | Écrit un caractère sur la sortie standard.         | ❌                            |
| [`ft_putstr`](#)            | Écrit une chaîne sur la sortie standard.           | ❌                            |
| [`ft_putendl`](#)           | Écrit une chaîne et un saut de ligne sur la sortie standard. | ❌                     |
| [`ft_putnbr`](#)            | Écrit un nombre sur la sortie standard.            | ❌                            |
| [`ft_putchar_fd`](#)        | Écrit un caractère sur un descripteur de fichier.  | ❌                            |
| [`ft_putstr_fd`](#)         | Écrit une chaîne sur un descripteur de fichier.    | ❌                            |
| [`ft_putendl_fd`](#)        | Écrit une chaîne et un saut de ligne sur un descripteur de fichier. | ❌                 |
| [`ft_putnbr_fd`](#)         | Écrit un nombre sur un descripteur de fichier.     | ❌                            |

### Bonus functions

| Fonction                     | Description                                                                    | Statut                        |
| ---------------------------- | ------------------------------------------------------------------------------ | ----------------------------- |
| [`ft_lstnew`](#)             | Alloue et renvoie un nouveau maillon de liste.                                  | ❌                            |
| [`ft_lstdelone`](#)          | Libère la mémoire d'un maillon de la liste.                                     | ❌                            |
| [`ft_lstdel`](#)             | Libère la mémoire d'une liste de maillons.                                      | ❌                            |
| [`ft_lstadd`](#)             | Ajoute un nouvel élément au début de la liste.                                  | ❌                            |
| [`ft_lstiter`](#)            | Itère sur la liste et applique une fonction à chaque maillon.                    | ❌                            |
| [`ft_lstmap`](#)             | Itère sur une liste et crée une nouvelle liste en appliquant une fonction.       | ❌                            |


---

Créé avec 💙 par [Berkrouber Benjamin](#)

---

