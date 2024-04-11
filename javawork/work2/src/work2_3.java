import java.util.Scanner;
public class work2_3 {
    public static void main(String[] args) {
        System.out.println("请输入一个正整数");
        int grade = 0;
        int next = 0;
        Scanner sc = new Scanner(System.in);
        grade = sc.nextInt();
        while(grade!=0)
        {
            next *= 10;
            next +=grade % 10;
            grade /= 10;

        }
        System.out.print("逆序输出整数为:");
        System.out.println(next);


    }
}