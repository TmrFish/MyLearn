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
        //        ѧ���ɼ�����
        System.out.println("ѧ���ɼ�����Ϊ:");
        System.out.println("���� ��ѧ Ӣ�� ���");
        for(int i = 0;i<students.length;i++){
            for(int j =0;j<students[i].length;j++){
                System.out.printf(students[i][j]+"  ");
            }
            System.out.printf("\n");
        }
        //        ���㲢���ÿλѧ�����ܳɼ�
        int Sums[] = getsums(students);
        System.out.printf("ѧ���ܳɼ�����Ϊ:"+Arrays.toString(Sums)+"\n");
        //        ����ܳɼ����ѧ�����к��Լ��ܳɼ�
        int max = getMax(Sums);
        int studnum = 0;
        for(int i = 0;i<Sums.length;i++){
            if (max == Sums[i]) {
                studnum = i + 1;
                break;
            }
        }
        System.out.printf("�ܳɼ���ߵ�ѧ���к�Ϊ:%d�����ܳɼ�Ϊ:%d\n",studnum,Sums[studnum-1]);
        //        ���ÿ����߷ּ��������к�
        int classgraude[][] = new int[students[0].length][students.length];
        for(int i = 0;i<students.length;i++){
            for (int j =0;j<students[i].length;j++){
                classgraude[j][i] = students[i][j];//���ɼ���ά����ߵ�
            }
        }
        int classsmax[] = new int[classgraude.length];
        int classsmax2[] = new int[classgraude.length];
        for (int i =0;i< classgraude.length;i++){
            classsmax[i] = getMax(classgraude[i]);//���ÿ�Ƴɼ�����ֵ
            classsmax2[i] = getMax2(classgraude[i]);//���ÿ�Ƴɼ����ֵ��ͬѧ�Ķ�Ӧ�к�
        }
        for (int i =0;i<classgraude.length;i++){
            System.out.printf("��%d���Ŀ��߳ɼ�Ϊ%d��ͬѧ�к�Ϊ%d\n",i+1,classsmax[i],classsmax2[i]);
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
