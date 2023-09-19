package com.Experiment.Ex7;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyListener implements ActionListener {
    private SimpleCaculator calc;

    public MyListener(SimpleCaculator o) {
        calc = o;
    }

    public void actionPerformed(ActionEvent e){
        try{
            String t1 = calc.getTf1().getText();
            String t2 = calc.getTf2().getText();
            int num1 = Integer.parseInt(t1);
            int num2 = Integer.parseInt(t2);

            double result = 0;
            if(e.getSource() == calc.getButton()[0]){
                calc.getLable().setText("+");
                result = num1 + num2;
            }
            else if(e.getSource() == calc.getButton()[1]){
                calc.getLable().setText("—");
                result = num1 - num2;
            }
            else if(e.getSource() == calc.getButton()[2]){
                calc.getLable().setText("*");
                result = num1 * num2;
            }
            else if (e.getSource() == calc.getButton()[3]){
                calc.getLable().setText("/");
                if(num2==0){
                    throw new ArithmeticException("分母不能为0");
                }
                result = num1 / num2;
            }

            calc.getTf3().setText(Double.toString(result));
        }
        catch (NumberFormatException ne){
            JOptionPane.showMessageDialog(null,"请输入整数");
        }
        catch (ArithmeticException ae){
            JOptionPane.showMessageDialog(null, "除数不能为零！");
        }
    }
}
