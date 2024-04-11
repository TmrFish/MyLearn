package work6;

class Electric {
    public String Name;
    public String Model;
    public String Colour;
    public String Cost;
    //-----------------------------------------------//
    public Electric(String name, String model, String colour, String cost) {
        super();
        Name = name;
        Model = model;
        Colour = colour;
        Cost = cost;
    }
    public Electric(){
        Name = new String();
        Model = new String();
        Colour = new String();
        Cost = new String();
    }
    //-----------------------------------------------//
    public String getName() {
        return Name;
    }
    public String getModel() {
        return Model;
    }
    public String getColour() {
        return Colour;
    }
    public String getCost() {
        return Cost;
    }
    //-----------------------------------------------//
    public String Data(){
        return "Ʒ��:"+Name+"\n�ͺ�:"+Model+"\n��ɫ:"+Colour+"\n�ۼ�:"+Cost;
    }
}

class Refrigerator extends Electric{
    public String Door;
    public String CoodPattern;
    //-----------------------------------------------//
    public Refrigerator(String name, String model, String colour, String cost, String door, String coodPattern) {
        super(name, model, colour, cost);
        Door = door;
        CoodPattern = coodPattern;
    }
    public Refrigerator(){
        super();
        Door = new String();
        CoodPattern = new String();
    }
    //-----------------------------------------------//
    public String getDoor() {
        return Door;
    }
    public String getCoodPattern() {
        return CoodPattern;
    }
    //-----------------------------------------------//
    public String Data(){
        return super.Data()+"\n�ſ�ʽ:"+Door+"\n���䷽ʽ:"+CoodPattern;
    }

}

class WashingMachine extends Electric{
    public String ElectModel;
    public String Capacity;

    //-----------------------------------------------//
    public WashingMachine(String name, String model, String colour, String cost, String electModel, String capacity) {
        super(name, model, colour, cost);
        ElectModel = electModel;
        Capacity = capacity;
    }
    public WashingMachine(){
        super();
        ElectModel = new String();
        Capacity = new String();
    }
    //-----------------------------------------------//
    public String getElectModel() {
        return ElectModel;
    }

    public String getCapacity() {
        return Capacity;
    }
    //-----------------------------------------------//
    public String Data(){
        return super.Data()+"\n�������:"+ElectModel+"\nϴ������:"+Capacity;
    }

}

class Tv extends Electric{
    public String Size;
    public String Resolution;

    //-----------------------------------------------//
    public Tv(String name, String model, String colour, String cost, String size, String resolution) {
        super(name, model, colour, cost);
        Size = size;
        Resolution = resolution;
    }
    public Tv(){
        super();
        Size = new String();
        Resolution = new String();
    }
//-----------------------------------------------//

    public String getSize() {
        return Size;
    }
    public String getResolution() {
        return Resolution;
    }
    //-----------------------------------------------//
    public String Data(){
        return super.Data()+"\n��Ļ�ߴ�:"+Size+"\n�ֱ���:"+Resolution;
    }

}

public class Work6_1Test {

    public static void main(String[] args) {
        System.out.println("//-----------------------------//");
        Refrigerator R1 = new Refrigerator("����","����","��ɫ","100000","˫����","ͭ������");
        System.out.println(R1.Data());
        System.out.println("//-----------------------------//");
        WashingMachine W1 = new WashingMachine("����","����ϴ�»�","��ɫ","29999","2000�����","100L");
        System.out.println(W1.Data());
        System.out.println("//-----------------------------//");
        Tv T1 = new Tv("����","����","��ɫ","6000","50��","4k");
        System.out.println(T1.Data());

    }

}