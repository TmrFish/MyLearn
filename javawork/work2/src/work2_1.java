import java.util.Scanner;
import java.util.Random;
public class work2_1 {
    public static void main(String[] args) {
        while (true){
            String playerin;
            int playerout = 0;
            int computer ;
            int out = 0;
            Scanner sc = new Scanner(System.in);
            System.out.println("欢迎来到猜拳游戏");
            System.out.println("到你出拳，请输入石头剪刀布:");
            playerin = sc.nextLine();
            if (playerin.equals("石头"))
                playerout = 0;
            else if (playerin.equals("剪刀"))
                playerout = 1;
            else if (playerin.equals("布"))
                playerout = 2;
            Random r = new Random();
            computer = r.nextInt(3);
            if (computer == 0)
            {
                System.out.println("电脑出了石头");
                if (playerout == 0)
                    out = 2;
                else if(playerout == 1)
                    out = 0;
                else if (playerout == 2)
                    out = 1;
            }
            else if (computer == 1)
            {
                System.out.println("电脑出了剪刀");
                if (playerout == 0)
                    out = 1;
                else if(playerout == 1)
                    out = 2;
                else if (playerout == 2)
                    out = 0;
            }
            else if (computer == 2)
            {
                System.out.println("电脑出了布");
                if (playerout == 0)
                    out = 0;
                else if(playerout == 1)
                    out = 1;
                else if (playerout == 2)
                    out = 2;
            }

            if (out == 0)
                System.out.println("你输了");
            else if(out == 1)
                System.out.println("你赢了");
            else if(out == 2)
                System.out.println("平局");





            System.out.println("游戏已结束是否重新开始，输入1为继续，输入0为结束");
            int a ;
            a =sc.nextInt();
            if (a == 1)
                continue;
            else
                break;
        }
    }


}

