package com.Experiment.Ex3;

public class Color {
    public int red,green,blue;
    public Color(){
        this(0,0,0);
    }
    public Color(int r,int g,int b){
        if (r>=0&&r<=255)
            red=r;
        else
            red=0;

        if (g>=0&&g<=255)
            green=g;
        else
            green=0;

        if (b>=0&&b<=255)
            blue=b;
        else
            blue=0;
    }

    public void setRed(int v){
        red=v;
    }
    public void setGreen(int v){
        green=v;
    }
    public void setBlue(int v){
        blue=v;
    }
    public int getRed()
    {
        return red;
    }

    public int getGreen() {
        return green;
    }

    public int getBlue() {
        return blue;
    }


}
