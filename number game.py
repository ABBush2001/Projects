import random



def question():
    
    uname = input("Hello, what is your name?")

    print("Hello", uname + ", nice to meet you!")

    question = input("Would you like to play a game? [yes/no]")
    if question == "no":
        print("Fine...")
    if question == "yes":
        game()

def game():
    
    number = random.randint(1, 10)
    tries = 1

    print("I'm thinking of a number between one and ten. Can you guess it?")
    guess = int(input("Take a guess: "))
    if guess > number:
        print("go lower...")
    if guess < number:
        print("go higher")
    while guess != number:
        tries += 1
        guess = int(input("Try again: "))
        if guess > number:
            print("go lower...")
    if guess == number:
        print("Congratulations! You guessed it!")
        print("It only took", tries, "tries!")

def retry():

    keepGoing = input("Would you like to play again?[yes/no]")

    while keepGoing == "yes":
        game()
        retry()
    print(" Ok, see you next time!")
    quit()


question()
retry()
