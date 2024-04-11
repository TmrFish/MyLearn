package giao;

import java.security.spec.RSAOtherPrimeInfo;
import java.util.Arrays;

public class test3_2 {
    public static void main(String[] args) {
        int first[] = {16,11,15,9,21,66};
        int second[] = {49,88,12,32,77,100};
        int sum[] = arrayMerge(first,second);
        System.out.printf("第一个数组是\n");
        System.out.print(Arrays.toString(first)+"\n");
        System.out.printf("第二个数组是\n");
        System.out.print(Arrays.toString(second)+"\n");
        System.out.printf("两个数组合成并排序后的数组是\n");
        System.out.print(Arrays.toString(sum));
    }
    public static int[] arrayMerge(int[] x ,int[] y){
        int Sum[] = new int[x.length+y.length];
        int i_cut = 0;
        for(int i=0;i<x.length;i++){
            Sum[i] = x[i];
            i_cut = i;
        }
        for(int j =0 ;j<y.length;j++){
            Sum[i_cut+1+j] = y[j];
        }
        int temp = 0;
        for(int i = 1;i<Sum.length;i++){
            int j = i-1;
            temp = Sum[i];
            for(;j>=0&&temp<Sum[j];j--){
                Sum[j+1]=Sum[j];
            }
            Sum[j+1] = temp;
        }
        return Sum;
    }

}
