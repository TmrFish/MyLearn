package work6;

abstract class Animal{
    String Name;
    String Variety;
    String Colour;
    int Age;

    public Animal(String name, String variety, String colour, int age) {
        Name = name;
        Variety = variety;
        Colour = colour;
        Age = age;
    }
    public Animal(){
        System.out.println("创建失败，请输入宠物信息");
    }
    public void eat(){
        System.out.println(Variety + Name +"在吃饭");
    }
    public void sleep(){
        System.out.println(Variety + Name +"在睡觉");
    }
    abstract public void Sound();
}

class Dog extends Animal{
    public Dog(String name, String variety, String colour, int age) {
        super(name, variety, colour, age);
    }
    public void Sound(){
        System.out.println("汪汪");
    }
}
class Cat extends Animal{
    public Cat(String name, String variety, String colour, int age) {
        super(name, variety, colour, age);
    }
    public void Sound(){
        System.out.println("喵喵");
    }

}
public class Work6_2Test {
    public static void main(String[] args){
        Animal cat1 = new Cat("小花","狸花猫","花色",8);
        cat1.eat();
        cat1.sleep();
        System.out.println("让她叫两声");
        cat1.Sound();
        Dog dog1 = new Dog("旺财","大黄狗","黄色",9);
        dog1.eat();
        dog1.sleep();
        System.out.println("让她叫两声");
        dog1.Sound();
    }
}
