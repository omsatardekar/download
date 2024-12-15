def deposit(balance, amount):
    return balance + amount

def withdraw(balance, amount):
    if balance >= amount:
        return balance - amount
    else:
        print("Insufficient balance:", balance)
        return balance

account_balance = 10000

while True:
    transaction = input("Enter transaction (e.g., 'D 100' or 'W 200') or 'exit' to quit: ")
    
    if transaction.lower() == 'exit':
        break
    
    try:
        operation, amount_str = transaction.split()
        amount = int(amount_str)
        
        if operation.upper() == "D":
            account_balance = deposit(account_balance, amount)
            print("Current Account balance is:", account_balance)
        elif operation.upper() == "W":
            account_balance = withdraw(account_balance, amount)
            print("Current Account balance is:", account_balance)
        else:
            print("Invalid operation:", operation)
    except ValueError:
        print("Invalid input format. Please enter in the format 'D 100' or 'W 200'.")
