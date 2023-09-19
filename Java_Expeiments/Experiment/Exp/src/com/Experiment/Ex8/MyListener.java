package com.Experiment.Ex8;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyListener implements ActionListener {
    private NotepadFrame frame;

    public MyListener(NotepadFrame frame) {
        this.frame = frame;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getActionCommand().equals("打开")) {
            if (frame.isModified()) {
                int option = JOptionPane.showConfirmDialog(frame, "当前文件已经修改，是否保存？", "提示",
                        JOptionPane.YES_NO_CANCEL_OPTION);
                if (option == JOptionPane.YES_OPTION) {
                    frame.saveFile();
                } else if (option == JOptionPane.CANCEL_OPTION) {
                    return;
                }
            }
            frame.openFile();
        } else if (e.getActionCommand().equals("保存")) {
            frame.saveFile();
        } else if (e.getActionCommand().equals("另存为")) {
            String currentFile = frame.getCurrentFile();
            frame.setCurrentFile(null);
            frame.saveFile();
            if (!frame.isModified()) {
                frame.setCurrentFile(currentFile);
            }
        } else if (e.getActionCommand().equals("退出")) {
            if (frame.isModified()) {
                int option = JOptionPane.showConfirmDialog(frame, "当前文件已经修改，是否保存？", "提示",
                        JOptionPane.YES_NO_CANCEL_OPTION);
                if (option == JOptionPane.YES_OPTION) {
                    frame.saveFile();
                } else if (option == JOptionPane.CANCEL_OPTION) {
                    return;
                }
            }
            System.exit(0);
        }
    }
}
