package samples.demo2.src.main.java.com.example.entities;

public class Individual extends Person {

    private Double healthExpenditures;

    public Individual(){
    }

    public Individual (Double healthExpenditures){
        this.healthExpenditures = healthExpenditures;
    }

    public Double getHealthExpenditures(){
        return healthExpenditures;
    }

    public void setHealthExpenditures(Double healthExpenditures){
        this.healthExpenditures = healthExpenditures;
    }

    Double CalcTax(){
        if (getyIncome() < 20000.00){
            return yIncome * 0.15 - (healthExpenditures * 0.5);
        }
        else {
            return yIncome * 0.25 - (healthExpenditures * 0.5);
        }
    }

    
}
