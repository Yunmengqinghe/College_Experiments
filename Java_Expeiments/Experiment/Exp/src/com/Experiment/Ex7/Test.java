package com.Experiment.Ex7;

import java.awt.event.ActionListener;

public class Test {
    public static void main(String[] args) {
        SimpleCaculator calc = new SimpleCaculator();
        MyListener myListener = new MyListener(calc);
        for(int i = 0;i < calc.getButton().length;i++){
            calc.getButton()[i].addActionListener(myListener);
        }
    }
}
