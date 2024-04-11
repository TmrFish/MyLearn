import java.util.Scanner;
public class work2_2 {
    public static void main(String[] args) {
        System.out.println("请输入你的成绩");
        int grade = 0;
        Scanner sc = new Scanner(System.in);
        grade = sc.nextInt();
        switch (grade / 10) {
            case 10:
                System.out.println("你的五级制成绩是：优秀");
                break;
            case 9:
                System.out.println("你的五级制成绩是：优秀");
                break;
            case 8:
                System.out.println("你的五级制成绩是：良好");
                break;
            case 7:
                System.out.println("你的五级制成绩是：中等");
                break;
            case 6:
                System.out.println("你的五级制成绩是：合格");
                break;
            case 5:
                System.out.println("你的五级制成绩是：不及格");
                break;
            case 4:
                System.out.println("你的五级制成绩是：不及格");
                break;
            case 3:
                System.out.println("你的五级制成绩是：不及格");
                break;
            case 2:
                System.out.println("你的五级制成绩是：不及格");
                break;
            case 1:
                System.out.println("你的五级制成绩是：不及格");
                break;
            case 0:
                System.out.println("你的五级制成绩是：不及格");
                break;
        }
    }
}
