package com.example.entities;

public class Legal extends Person {
    //tax
    private final Double TAX = 0.16;
    private final Double TAX10 = 0.14;

    private Integer numbersEmployees;

    public Legal(){
        super();
    }

    public Legal (String name, Double yIncome, Integer numbersEmployees){
        super(name, yIncome);
        this.numbersEmployees = numbersEmployees;
        Person.addPerson(this);
    }

    public Integer getNumbersEmployees() {
        return numbersEmployees;
    }

    public Double getYIncome() {
        return yIncome;
    }

    public void setNumbersEmployees(Integer numbersEmployees) {
        this.numbersEmployees = numbersEmployees;
    }

    public void setYIncome(Double yIncome) {
        this.yIncome = yIncome;
    }


    public Double calculateTax(){
        if (numbersEmployees > 10){
            return yIncome * TAX10;
        } else {
            return yIncome * TAX;
        }
    }




}