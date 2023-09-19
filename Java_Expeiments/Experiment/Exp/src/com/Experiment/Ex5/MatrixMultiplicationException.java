package com.Experiment.Ex5;

public class MatrixMultiplicationException extends Exception{
    public MatrixMultiplicationException(String message) {
        super(message);
    }

    @Override
    public String toString() {
        return "MatrixMultiplicationException:" + getMessage();
    }
}
