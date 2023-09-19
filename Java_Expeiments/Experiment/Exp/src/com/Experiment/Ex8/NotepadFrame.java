package com.Experiment.Ex8;

import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;

public class NotepadFrame extends JFrame {
    private JTextArea textArea;
    private JFileChooser fileChooser;
    private String currentFile;
    private boolean modified;

    public NotepadFrame() {
        super("简易编辑器");
        setSize(600, 400);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        setLayout(new BorderLayout());

        // 菜单栏
        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("文件");
        JMenuItem openMenuItem = new JMenuItem("打开");
        JMenuItem saveMenuItem = new JMenuItem("保存");
        JMenuItem saveAsMenuItem = new JMenuItem("另存为");
        JMenuItem exitMenuItem = new JMenuItem("退出");

        // 文件选择器
        fileChooser = new JFileChooser();
        fileChooser.setFileFilter(new FileNameExtensionFilter("文本文件(*.txt)", "txt"));

        // 添加菜单项
        fileMenu.add(openMenuItem);
        fileMenu.add(saveMenuItem);
        fileMenu.add(saveAsMenuItem);
        fileMenu.addSeparator();
        fileMenu.add(exitMenuItem);
        menuBar.add(fileMenu);
        setJMenuBar(menuBar);

        // 文本编辑区域
        textArea = new JTextArea();
        JScrollPane scrollPane = new JScrollPane(textArea);
        add(scrollPane, BorderLayout.CENTER);

        // 监听窗口关闭事件，如果文件已经修改，则提示用户是否保存修改结果
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                if (modified) {
                    int option = JOptionPane.showConfirmDialog(NotepadFrame.this,
                            "当前文件已经修改，是否保存？", "提示", JOptionPane.YES_NO_CANCEL_OPTION);
                    if (option == JOptionPane.YES_OPTION) {
                        saveFile();
                    } else if (option == JOptionPane.CANCEL_OPTION) {
                        return;
                    }
                }
                System.exit(0);
            }
        });

        // 监听菜单项事件
        openMenuItem.addActionListener(new MyListener(this));
        saveMenuItem.addActionListener(new MyListener(this));
        saveAsMenuItem.addActionListener(new MyListener(this));
        exitMenuItem.addActionListener(new MyListener(this));
    }

    // 获取文本编辑区域
    public JTextArea getTextArea() {
        return textArea;
    }

    // 获取文件选择器
    public JFileChooser getFileChooser() {
        return fileChooser;
    }

    // 获取当前文件名
    public String getCurrentFile() {
        return currentFile;
    }

    // 设置当前文件名
    public void setCurrentFile(String currentFile) {
        this.currentFile = currentFile;
    }

    // 判断文件是否被修改
    public boolean isModified() {
        return modified;
    }

    // 设置文件修改状态
    public void setModified(boolean modified) {
        this.modified = modified;
    }

    // 保存文件
    public void saveFile() {
        BufferedWriter writer = null;
        try {
            if (currentFile == null) {
                int result = fileChooser.showSaveDialog(this);
                if (result == JFileChooser.APPROVE_OPTION) {
                    File file = fileChooser.getSelectedFile();
                    currentFile = file.getAbsolutePath();
                } else {
                    return;
                }
            }
            writer = new BufferedWriter(new FileWriter(currentFile));
            writer.write(textArea.getText());
            modified = false;
        } catch (IOException e) {
            JOptionPane.showMessageDialog(this, "保存文件失败！", "错误", JOptionPane.ERROR_MESSAGE);
        } finally {
            try {
                if (writer != null) {
                    writer.close();
                }
            } catch (IOException e) {
                JOptionPane.showMessageDialog(this, "关闭文件失败！", "错误", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    // 打开文件
    public void openFile() {
        BufferedReader reader = null;
        try {
            int result = fileChooser.showOpenDialog(this);
            if (result == JFileChooser.APPROVE_OPTION) {
                File file = fileChooser.getSelectedFile();
                reader = new BufferedReader(new FileReader(file));
                String line;
                StringBuilder sb = new StringBuilder();
                while ((line = reader.readLine()) != null) {
                    sb.append(line).append("\n");
                }
                textArea.setText(sb.toString());
                currentFile = file.getAbsolutePath();
                modified = false;
            }
        } catch (IOException e) {
            JOptionPane.showMessageDialog(this, "打开文件失败！", "错误", JOptionPane.ERROR_MESSAGE);
        } finally {
            try {
                if (reader != null) {
                    reader.close();
                }
            } catch (IOException e) {
                JOptionPane.showMessageDialog(this, "关闭文件失败！", "错误", JOptionPane.ERROR_MESSAGE);
            }
        }
    }
}
