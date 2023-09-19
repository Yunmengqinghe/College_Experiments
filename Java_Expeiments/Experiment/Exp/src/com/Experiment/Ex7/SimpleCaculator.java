package com.Experiment.Ex7;

import javax.swing.*;
import java.awt.*;

public class SimpleCaculator extends JFrame{
    public JTextField tf1,tf2,tf3;
    public JLabel lable;
    public JButton[] button;
    public SimpleCaculator() {
        setTitle("简易计算器");
        setSize(500,300);
        GridLayout layout = new GridLayout();
        layout.setRows(2);
        setLayout(layout);

        JPanel top = new JPanel();
        FlowLayout flTop = new FlowLayout(1,20,5);
        tf1 = new JTextField(10);
        tf2 = new JTextField(10);
        tf3 = new JTextField(10);
        lable = new JLabel("+");
        top.add(tf1);
        top.add(lable);
        top.add(tf2);
        top.add(new JLabel("="));
        top.add(tf3);
        top.setLayout(flTop);
        add(top);


        JPanel bottom = new JPanel();
        FlowLayout flBottom = new FlowLayout();
        bottom.setLayout(flBottom);
        button = new JButton[4];
        button[0] = new JButton("+");
        button[1] = new JButton("—");
        button[2] = new JButton("*");
        button[3] = new JButton("/");

        for(int i = 0; i < button.length; i++){
            button[i].setPreferredSize(new Dimension(80,40));
            bottom.add(button[i]);
        }
        add(bottom);

        setLocation(625,350);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public JTextField getTf1() {
        return tf1;
    }

    public JTextField getTf2() {
        return tf2;
    }

    public JTextField getTf3() {
        return tf3;
    }

    public JButton[] getButton() {
        return button;
    }

    public JLabel getLable() {
        return lable;
    }
}
