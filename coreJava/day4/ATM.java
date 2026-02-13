package day4;

public class ATM {
    int balance = 0;

    public ATM(int balance) {
        this.balance = balance;
    }

    public void withdraw(int amount) throws CustomException {
        if (amount > balance) {
            throw new CustomException("You do not have enough balance for this transaction");
        }
        this.balance -= amount;
    }

    public void deposit(int amount) throws CustomException {
        if (amount <= 0) {
            throw new CustomException("amount must be +ve number greater than 0 in order to be able to add to balance");
        }
        balance += amount;
    }

    public boolean checkLimit(int limit) throws CustomException {
        if (limit > 500) {
            throw new CustomException("limit is out of range::::");
        }
        return true;
    }
}
