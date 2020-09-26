
def add():
    num1 = int(input("What is the first number you are adding?"))
    num2 = int(input("What is the second number you are adding?"))
    num3 = num1 + num2
    print(num1, "+", num2, "=", num3)

def subtract():
    num1 = int(input("What is the first number you are subtracting?"))
    num2 = int(input("What is the second number you are subtracting?"))
    num3 = num1 - num2
    print(num1, "-", num2, "=", num3)

def multiply():
    num1 = int(input("What is the first number you are multiplying?"))
    num2 = int(input("What is the second number you are multiplying?"))
    num3 = num1 * num2
    print(num1, "*", num2, "=", num3)

def divide():
    num1 = int(input("What is the numerator?"))
    num2 = int(input("What is the denominator?"))
    num3 = num1 / num2
    print(num1, "/", num2, "=", num3)

def calculator():
    mathQuestion = input("ok, do you want to add, subtract, multiply or divide?")
    if mathQuestion == "add":
        add()
    if mathQuestion == "subtract":
        subtract()
    if mathQuestion == "divide":
        divide()
    if mathQuestion == "multiply":
        multiply()

def query():
    question = input("Would you like to use the calculator? [yes/no]")
    if question == "no":
        print("ok, see ya later!")
    if question == "yes":
        calculator()


def main():

    cont = input("Are you finished?")
    if cont == "yes":
        print("See ya")
        quit()
    if cont == "no":
        while cont == "no":
            calculator()
            main()

            
query()
main()
