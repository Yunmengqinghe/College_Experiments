package com.Experiment.Ex5;

import javax.management.RuntimeMBeanException;

public class IllegalIndexException extends Exception {
    public IllegalIndexException(String message) {
        super(message);
    }

    @Override
    public String toString() {
        return "IllegalIndexException:" + getMessage();
    }
}
