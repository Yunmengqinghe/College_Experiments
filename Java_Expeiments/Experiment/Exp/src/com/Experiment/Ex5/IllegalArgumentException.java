package com.Experiment.Ex5;

public class IllegalArgumentException extends Exception{
    public IllegalArgumentException(String message) {
        super(message);
    }

    @Override
    public String toString() {
        return "IllegalArgumentException:" + getMessage();
    }
}
