package samples.demo2.src.main.java.com.example.entities;

public class Legal extends Person {
    //tax
    private final Double TAX = 0.16;
    private final Double TAX10 = 0.14;

    private Integer numbersEmployees;

    public Legal(){
    }

    public Legal (String name, Double yIncome, Integer numbersEmployees){
        super(name, yIncome);
        this.numbersEmployees = numbersEmployees;
    }

    public Integer getNumbersEmployees() {
        return numbersEmployees;
    }

    public void setNumbersEmployees(Integer numbersEmployees) {
        this.numbersEmployees = numbersEmployees;
    }


    public Double calculateTax(){
        if (numbersEmployees > 10){
            return yIncome * TAX10;
        } else {
            return yIncome * TAX;
        }
    }




}
