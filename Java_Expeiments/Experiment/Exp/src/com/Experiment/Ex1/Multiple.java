package com.Experiment.Ex1;

public class Multiple {
        public void firstType()
        {
            for(int i=1;i<=9;i++) {
                for(int j=1;j<=i;j++) {
                    System.out.print(i + "*" + j + "=" + i*j + "\t");
                }
                System.out.println();
            }
        }

        public void secondType() {
            for(int i=1;i<=9;i++) {
                for(int k=1;k<i;k++) {
                    System.out.print("\t\t");
                }
                for(int j=i;j<=9;j++){
                    System.out.print(j + "*" + i + "=" + i*j + "\t");
                }
                System.out.println();
            }
        }

        public void thirdType(){
            for(int i=1;i<=9;i++) {
                for(int k=0;k<9-i;k++) {
                    System.out.print("\t");
                }
                for(int j=1;j<=i;j++){
                    System.out.print(j + "*" + i + "=" + i*j + "\t");
                }
                System.out.println();
            }
        }
}
