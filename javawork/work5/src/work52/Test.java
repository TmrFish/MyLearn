package work52;

public class Test {
    public static void main(String[] args) {
        Myself me = new Myself("谭名瑞",20,"男","大数据技术");
        //public方法公开可运行
        //public范围：同一个类，同一个包，子类，全局
        me.introduce();
        //default方法同一个包中可运行
        //default范围：同一个类，同一个包
        me.InDuAge();
        //private方法不在同一个类无法运行
        //private范围：同一个类
//        me.InDuName();'InDuName()' 在 'work52.Myself' 中具有 private 访问权限
    }
}
