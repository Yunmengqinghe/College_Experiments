package com.Experiment.Ex5;

import java.util.Arrays;

public class ArrayReverser {
    int[] data;

    public ArrayReverser(int[] data) {
        if (data==null)
            this.data = new int[0];
        else
            this.data = data;
    }

    public int[] getData() {
        return data;
    }

    public void setData(int[] data) {
        if(data!=null)
            this.data = data;
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder("[");
        for(int i = 0;i < data.length; i++){
            s.append(data[i]);
            if (i<data.length-1){
                s.append(",");
            }
        }
        s.append("]");
        return s.toString();
    }

    public void reverse(){
        for(int i=0;i<data.length/2;i++){
            int k=data[i];
            data[i]=data[data.length-1-i];
            data[data.length-1-i]=k;
        }
    }
}
