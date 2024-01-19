package com.example.entities;

import java.util.ArrayList;
import java.util.List;

public class Person {

    private String name;
    protected Double yIncome;
    protected Double taxPaid;

    private static List <Person> list = new ArrayList<>();

    public Person(){
    }

    public Person(String name, Double yIncome){
        this.name = name;
        this.yIncome = yIncome;
        /* Person.addPerson(this); */
    }

    public String getName(){
        return name;
    }

    public Double getyIncome(){
        return yIncome;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setyIncome(Double yIncome){
        this.yIncome = yIncome;
    }

    public Double getTaxPaid(){
        return taxPaid;
    }

    public void setTaxPaid(Double taxPaid){
        this.taxPaid = taxPaid;
    }

    public static void addPerson(Person person){
        list.add(person);
    }

    public static void removePerson(Person person){
        list.remove(person);
    }

    public static List<Person> getList(){
        return list;
    }

    public String toString(){
        return name + ": $ " + String.format("%.2f", taxPaid);
    }

    public static Double calcTotalTax(){
        Double sum = 0.0;
        for (Person person : list){
            sum += person.getTaxPaid();
        }
        return sum;
    }

}

