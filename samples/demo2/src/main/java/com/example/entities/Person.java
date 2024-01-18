package samples.demo2.src.main.java.com.example.entities;

public class Person {

    private String name;
    protected Double yIncome;
    private Double taxPaid;

    public Person(){
    }

    public Person(String name, Double yIncome){
        this.name = name;
        this.yIncome = yIncome;
    }

    public String getName(){
        return name;
    }

    public Double getyIncome(){
        return yIncome;
    }

    public Double getTaxPaid(){
        return taxPaid;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setyIncome(Double yIncome){
        this.yIncome = yIncome;
    }

    public void setTaxPaid(Double taxPaid){
        this.taxPaid = taxPaid;
    }
}

