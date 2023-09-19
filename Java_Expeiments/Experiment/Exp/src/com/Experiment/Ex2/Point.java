package com.Experiment.Ex2;

public class Point {
    public int x,y;
    public Point(){
        this(0,0);
    }
    public Point(int x,int y) {
        this.x=x;
        this.y=y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
    public void setX(int x) {
        this.x=x;
    }

    public void setY(int y) {
        this.y=y;
    }

    public double distance(Point p) {
        double d = Math.pow((p.x-x),2) + Math.pow(p.y-y,2);
        return Math.sqrt(d);
    }
}
