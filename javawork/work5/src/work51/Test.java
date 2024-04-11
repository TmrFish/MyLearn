package work51;

public class Test {
    public static void main(String[] args) {
        //测试长方形
        Rectangle R1 = new Rectangle(4,6);
        //测试正方形
        Rectangle R2 = new Rectangle(5);
        System.out.printf("R1长方形(%.1f,%.1f)的周长:%.1f\n",R1.getLong(),R1.getWide(),R1.chang());
        System.out.printf("R1长方形(%.1f,%.1f)的面积:%.1f\n",R1.getLong(),R1.getWide(),R1.mianji());
        System.out.printf("R2正方形(%.1f,%.1f)的周长:%.1f\n",R2.getLong(),R2.getWide(),R2.chang());
        System.out.printf("R2正方形(%.1f,%.1f)的面积:%.1f\n",R2.getLong(),R2.getWide(),R2.mianji());
    }
}
