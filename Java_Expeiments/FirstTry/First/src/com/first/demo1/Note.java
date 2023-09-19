package com.first.demo1;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Note extends JFrame {
    Note() {
        setSize(500,80);
        setTitle("图形界面应用");
        FlowLayout flowLayout = new FlowLayout();
        setLayout(flowLayout);

        JLabel jLabel = new JLabel("单击按钮时文字会改编成文本框内容");
        JTextArea jTextArea = new JTextArea(1,15);
        JButton jButton = new JButton("更改文字");
        jButton.setSize(20,20);
        add(jLabel);
        add(jTextArea);
        add(jButton);

        jButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null,"成功");
                String text = jTextArea.getText();
                jLabel.setText(text);
            }
        });

        pack();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);


    }
}