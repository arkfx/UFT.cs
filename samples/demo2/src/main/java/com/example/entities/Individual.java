package com.example.entities;

public class Individual extends Person {

    private Double healthExpenditures;

    public Individual(){
        super();
    }
    
    public Individual(String name, Double yIncome, Double healthExpenditures){
        super(name, yIncome);
        this.healthExpenditures = healthExpenditures;
        Person.addPerson(this);
    }


    public Double calcTax(){
        if (getyIncome() < 20000.00){
            return yIncome * 0.15 - (healthExpenditures * 0.5);
        }
        else {
            return yIncome * 0.25 - (healthExpenditures * 0.5);
        }
    }

    
}
