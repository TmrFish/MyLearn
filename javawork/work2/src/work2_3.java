import java.util.Scanner;
public class work2_3 {
    public static void main(String[] args) {
        System.out.println("������һ��������");
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
        System.out.print("�����������Ϊ:");
        System.out.println(next);


    }
}