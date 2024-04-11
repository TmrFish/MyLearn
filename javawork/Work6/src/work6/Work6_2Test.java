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
        System.out.println("����ʧ�ܣ������������Ϣ");
    }
    public void eat(){
        System.out.println(Variety + Name +"�ڳԷ�");
    }
    public void sleep(){
        System.out.println(Variety + Name +"��˯��");
    }
    abstract public void Sound();
}

class Dog extends Animal{
    public Dog(String name, String variety, String colour, int age) {
        super(name, variety, colour, age);
    }
    public void Sound(){
        System.out.println("����");
    }
}
class Cat extends Animal{
    public Cat(String name, String variety, String colour, int age) {
        super(name, variety, colour, age);
    }
    public void Sound(){
        System.out.println("����");
    }

}
public class Work6_2Test {
    public static void main(String[] args){
        Animal cat1 = new Cat("С��","�껨è","��ɫ",8);
        cat1.eat();
        cat1.sleep();
        System.out.println("����������");
        cat1.Sound();
        Dog dog1 = new Dog("����","��ƹ�","��ɫ",9);
        dog1.eat();
        dog1.sleep();
        System.out.println("����������");
        dog1.Sound();
    }
}
