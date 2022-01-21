import random
import winsound
from words import word_list


def get_word():
    word = random.choice(word_list)
    return word.upper()


def play(word):
    word_completion = "_" * len(word)
    guessed = False
    guessed_letters = []
    guessed_words = []
    tries = 6
    print("Juguemos al ahorcado!")
    print(display_hangman(tries))
    print(word_completion)
    print("\n")
    while not guessed and tries > 0:
        guess = input("Descubre una letra o la palabra completa: ").upper()
        if len(guess) == 1 and guess.isalpha():
            if guess in guessed_letters:
                print("Ya descubriste la palabra", guess)
            elif guess not in word:
                print(guess, "no esta en la palabra.")
                tries -= 1
                guessed_letters.append(guess)
            else:
                print("Buen trabajo,", guess, "si esta en la palabra!")
                guessed_letters.append(guess)
                word_as_list = list(word_completion)
                indices = [i for i, letter in enumerate(word) if letter == guess]
                for index in indices:
                    word_as_list[index] = guess
                word_completion = "".join(word_as_list)
                if "_" not in word_completion:
                    guessed = True
        elif len(guess) == len(word) and guess.isalpha():
            if guess in guessed_words:
                print("Ya descubriste la palabra", guess)
            elif guess != word:
                print(guess, "No es la palabra.")
                tries -= 1
                guessed_words.append(guess)
            else:
                guessed = True
                word_completion = word
        else:
            print("No es una respuesta valida.")
        print(display_hangman(tries))
        print(word_completion)
        print("\n")
    if guessed:
        print("Felicidades, has descubierto la palabra, ganaste!!!!")
        winsound.PlaySound("win.wav", winsound.SND_ASYNC)
    else:
        print("Lo siento, te quedaste sin intentos, la palabra era: " + word + ". A lo mejor a la siguiente!")


def display_hangman(tries):
    stages = [  # final state: head, torso, both arms, and both legs
                """
                   --------
                   |      |
                   |      O
                   |     \\|/
                   |      |
                   |     / \\
                   -
                """,
                # head, torso, both arms, and one leg
                """
                   --------
                   |      |
                   |      O
                   |     \\|/
                   |      |
                   |     / 
                   -
                """,
                # head, torso, and both arms
                """
                   --------
                   |      |
                   |      O
                   |     \\|/
                   |      |
                   |      
                   -
                """,
                # head, torso, and one arm
                """
                   --------
                   |      |
                   |      O
                   |     \\|
                   |      |
                   |     
                   -
                """,
                # head and torso
                """
                   --------
                   |      |
                   |      O
                   |      |
                   |      |
                   |     
                   -
                """,
                # head
                """
                   --------
                   |      |
                   |      O
                   |    
                   |      
                   |     
                   -
                """,
                # initial empty state
                """
                   --------
                   |      |
                   |      
                   |    
                   |      
                   |     
                   -
                """
    ]
    return stages[tries]


def main():
    word = get_word()
    play(word)
    while input("Le gustaria jugar de nuevo? (S/N) ").upper() == "S":
        word = get_word()
        play(word)


if __name__ == "__main__":
    main()
