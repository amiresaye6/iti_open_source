package day4;

public class CustomException extends Exception {
    String message;

    public CustomException(String message) {
        super("custom exception :__:" + message);
        this.message = message;
    }
}
