package giao;

import java.util.Arrays;

public class test3_3 {
    public static void main(String[] args) {
        int [][] students = {
                {80,75,78,93},
                {68,87,98,65},
                {86,72,60,76},
                {76,80,76,63},
                {82,90,90,80}
        };
        //        学生成绩矩阵
        System.out.println("学生成绩矩阵为:");
        System.out.println("语文 数学 英语 编程");
        for(int i = 0;i<students.length;i++){
            for(int j =0;j<students[i].length;j++){
                System.out.printf(students[i][j]+"  ");
            }
            System.out.printf("\n");
        }
        //        计算并输出每位学生的总成绩
        int Sums[] = getsums(students);
        System.out.printf("学生总成绩数组为:"+Arrays.toString(Sums)+"\n");
        //        输出总成绩最高学生的行号以及总成绩
        int max = getMax(Sums);
        int studnum = 0;
        for(int i = 0;i<Sums.length;i++){
            if (max == Sums[i]) {
                studnum = i + 1;
                break;
            }
        }
        System.out.printf("总成绩最高的学生行号为:%d，其总成绩为:%d\n",studnum,Sums[studnum-1]);
        //        输出每科最高分及其所在行号
        int classgraude[][] = new int[students[0].length][students.length];
        for(int i = 0;i<students.length;i++){
            for (int j =0;j<students[i].length;j++){
                classgraude[j][i] = students[i][j];//将成绩二维数组颠倒
            }
        }
        int classsmax[] = new int[classgraude.length];
        int classsmax2[] = new int[classgraude.length];
        for (int i =0;i< classgraude.length;i++){
            classsmax[i] = getMax(classgraude[i]);//求出每科成绩最大的值
            classsmax2[i] = getMax2(classgraude[i]);//求出每科成绩最大值的同学的对应行号
        }
        for (int i =0;i<classgraude.length;i++){
            System.out.printf("第%d项科目最高成绩为%d该同学行号为%d\n",i+1,classsmax[i],classsmax2[i]);
        }
    }

    public static int[] getsums(int[][] students) {
        int sums[] = new int[students.length];
        int i =0;
        for(;i<students.length;i++){
            int sum = 0;
            for(int j=0;j<students[i].length;j++){
                sum += students[i][j];
            }
            sums[i] = sum;
        }
        return sums;
    }
    public static int getMax(int[] a){
        int Max = a[0];
        for(int i = 1;i<a.length;i++){
            if(a[i]>Max){
                Max = a[i];
            }
        }
        return Max;
    }
    public static int getMax2(int[] a){
        int Max = a[0];
        for(int i = 1;i<a.length;i++){
            if(a[i]>Max){
                Max = a[i];
            }
        }
        int classnum = 0;
        for(int i = 0;i<a.length;i++){
            if (Max == a[i]) {
                classnum = i + 1;
                break;
            }
        }
        return classnum;
    }
}
