print ("Hello, Welcome to a calculator written in python!")
def print_menu():       ## Your menu design here
    print (30 * "-" , "MENU" , 30 * "-")
    print ("Press 1 for: Addition")
    print ("Press 2 for: Subtraction")
    print ("Press 3 for: Multiplication")
    print ("Press 4 for: Division")
    print ("Press 5 to exit")
    print (67 * "-")
loop = True      
while loop:          ## While loop which will keep going until loop = False
    print_menu()    ## Displays menu
    val = input("Enter your choice [1-5]:")
    val = int(val)
    if val == 1:
        print ("Please enter two numbers you would like to add")
        num1 = input("First number ")
        num1 = int(num1)
        num2 = input("Second number ")
        num2 = int(num2)
        num = num1 + num2
        print (num)
    elif val == 2:
        print ("Please enter two numbers you would like to subtract")
        num1 = input("First number ")
        num1 = int(num1)
        num2 = input("Second number ")
        num2 = int(num2)
        num = num1 - num2
        print (num)
    elif val == 3:
        print ("Please enter two numbers you would like to multiply")
        num1 = input("First number ")
        num1 = int(num1)
        num2 = input("Second number ")
        num2 = int(num2)
        num = num1*num2
        print (num)
    elif val == 4:
        print ("Please enter two numbers you would like to divide")
        num1 = input("First number ")
        num1 = int(num1)
        num2 = input("Second number ")
        num2 = int(num2)
        num = num1/num2
        print (num)
    elif val == 5:
        print ("Goodbye")
        loop = False
    else: 
        print ("Please select a number between 1-5 ")