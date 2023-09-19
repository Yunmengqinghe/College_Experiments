package com.Experiment.Ex4;

import com.Experiment.Ex2.Circle;
import com.Experiment.Ex2.Point;

public class Ex4_Circle extends Circle {
    public Ex4_Circle(){
        super();
    }

    public Ex4_Circle(int x, int y, int r) {
        super(x, y, r);
    }

    public Ex4_Circle(Point c, int r) {
        super(c, r);
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Circle circle){
            if(circle.getRadius()==getRadius()){
                if(circle.getCenter().getX()==getCenter().getX() &&
                        circle.getCenter().getY()== getCenter().getY()){
                    return true;
                }
            }
        }
        return false;
    }

    @Override
    public String toString() {
        return "(" + getCenter().getX() + "," + getCenter().getY() + ")," +getRadius();
    }
}
