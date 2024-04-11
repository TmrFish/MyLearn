package work52;

public class Myself {
    //成员变量
     public String name;//姓名
     private int age;//年龄
     String sex;//性别
     protected String major;//专业
    //构造方法
    //无参
    public  Myself(){

    }
    //有参
    public Myself(String name, int age, String sex, String major) {
        this.name = name;
        this.age = age;
        this.sex = sex;
        this.major = major;
    }
    //自我介绍
    public void introduce(){
        System.out.printf("我叫%s,今年%d岁,我的性别是%s，我的专业是%s。\n",this.name,this.age,this.sex,this.major);
    }
    private void InDuName(){
        System.out.println(this.name);
    }
    void InDuAge(){
        System.out.println(this.age);
    }


}
