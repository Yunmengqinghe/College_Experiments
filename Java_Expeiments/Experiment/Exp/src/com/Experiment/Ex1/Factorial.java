package com.Experiment.Ex1;

import java.security.PrivateKey;

public class Factorial {
    private long sum=1;

    public Factorial() {
        sum = 1;
    }

    public void Multiple(){
        for(long i=1;i<=20;i++) {
            for(long j=1;j<=i;j++){
                sum*=j;
            }
            System.out.print(i + "!" + "=" + sum);
            System.out.println();
            sum=1;
        }
    }

}
