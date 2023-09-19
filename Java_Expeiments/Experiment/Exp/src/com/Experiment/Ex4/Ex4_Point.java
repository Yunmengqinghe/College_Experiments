package com.Experiment.Ex4;

import com.Experiment.Ex2.Point;

public class Ex4_Point extends Point {
    public Ex4_Point() {
        super();
    }

    public Ex4_Point(int x, int y) {
        super(x, y);
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Point point){
            if(point.getX()==getX() && point.getY()==getY()){
                return true;
            }
        }
        return false;
    }

    @Override
    public String toString() {
        return "(" + x + "," + y + ")";
    }
}
