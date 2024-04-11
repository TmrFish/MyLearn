import java.util.Scanner;

public class work1_2 {
    public static void main(String[] args) {
        char add;
        char out;
        Scanner scan = new Scanner(System.in);
        System.out.println("请输入原文");
        String input1 = scan.next();
        char[] yuan = input1.toCharArray();
        System.out.println("原文是");
        for(int i = 0;i< yuan.length;i++){
            char yuanson = yuan[i];
            System.out.print(yuanson);

        }
        System.out.println("\n密文是");
        for(int i = 0;i< yuan.length;i++){
            char yuanson = yuan[i];
            add = (char)(yuanson ^ 'A');
            System.out.print(add);
        }
        System.out.println("\n译文是");
        for(int i = 0;i< yuan.length;i++){
            char yuanson = yuan[i];
            add = (char)(yuanson ^ 'A');
            out = (char)(add ^ 'A');
            System.out.print(out);
        }
    }
}