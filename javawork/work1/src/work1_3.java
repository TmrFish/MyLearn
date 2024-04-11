import java.util.Scanner;

public class work1_3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.printf("请输入一个三位数:");
        int num = input.nextInt();
        input.close();
        System.out.printf("这个三位数是%d\n", num);
        int one;
        int ten;
        int hundred;
        one = num % 10;
        System.out.printf("个位数是%d\n", one);
        ten = num / 10 % 10;
        System.out.printf("十位数是%d\n", ten);
        hundred = num / 100 % 10;
        System.out.printf("百位数是%d\n", hundred);
        int add;
        add = one + ten + hundred;
        System.out.printf("三位数和是%d\n", add);
    }
}
