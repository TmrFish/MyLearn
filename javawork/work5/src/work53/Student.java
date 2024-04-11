package work53;

public class Student {
    private String id;
    private String name;
    private String major;
    private String school;

    public Student(String id, String name, String major, String school) {
        this.id = id;
        this.name = name;
        this.major = major;
        this.school = school;
    }
    public Student(){

    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getMajor() {
        return major;
    }

    public void setMajor(String major) {
        this.major = major;
    }

    public String getSchool() {
        return school;
    }

    public void setSchool(String school) {
        this.school = school;
    }
}
