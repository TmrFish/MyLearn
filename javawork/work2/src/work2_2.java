import java.util.Scanner;
public class work2_2 {
    public static void main(String[] args) {
        System.out.println("��������ĳɼ�");
        int grade = 0;
        Scanner sc = new Scanner(System.in);
        grade = sc.nextInt();
        switch (grade / 10) {
            case 10:
                System.out.println("����弶�Ƴɼ��ǣ�����");
                break;
            case 9:
                System.out.println("����弶�Ƴɼ��ǣ�����");
                break;
            case 8:
                System.out.println("����弶�Ƴɼ��ǣ�����");
                break;
            case 7:
                System.out.println("����弶�Ƴɼ��ǣ��е�");
                break;
            case 6:
                System.out.println("����弶�Ƴɼ��ǣ��ϸ�");
                break;
            case 5:
                System.out.println("����弶�Ƴɼ��ǣ�������");
                break;
            case 4:
                System.out.println("����弶�Ƴɼ��ǣ�������");
                break;
            case 3:
                System.out.println("����弶�Ƴɼ��ǣ�������");
                break;
            case 2:
                System.out.println("����弶�Ƴɼ��ǣ�������");
                break;
            case 1:
                System.out.println("����弶�Ƴɼ��ǣ�������");
                break;
            case 0:
                System.out.println("����弶�Ƴɼ��ǣ�������");
                break;
        }
    }
}
