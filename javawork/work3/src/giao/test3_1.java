package giao;
import java.util.Scanner;

public class test3_1 {
    public static void main(String[] args){
        double six[] = new double[6];
        Scanner input = new Scanner(System.in);
        System.out.println("����������С��");
        for(int i = 0;i<6;i++){
            six[i] = input.nextDouble();
        }
        double sum = 0;
        for(int i = 0;i<six.length;i++){
            sum += six[i];
        }
        System.out.printf("Ԫ�غ�Ϊ:%.2f\n",sum);
        double max = getMax(six);
        System.out.printf("���ֵΪ:%.2f\n",max);
        double min = getMin(six);
        System.out.printf("��СֵΪ:%.2f\n",min);
        double aver = getaver(six);
        System.out.printf("ƽ��ֵΪ:%.2f\n",aver);
    }
    public static double getMax(double[] a){
        double Max = a[0];
        for(int i = 1;i<a.length;i++){
            if(a[i]>Max){
                Max = a[i];
            }
        }
        return Max;
    }
    public static double getMin(double[] a){
        double Min = a[0];
        for(int i = 1;i<a.length;i++){
            if(a[i]<Min){
                Min = a[i];
            }
        }
        return Min;
    }
    public static double getaver(double[] a){
        double aver;
        double sum = 0;
        for(int i = 0;i<a.length;i++){
            sum += a[i];
        }
        aver = sum/a.length;
        return aver;
    }
}
