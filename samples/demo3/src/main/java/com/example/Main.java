package com.example;

//payment interface

public class Main {
    public static void main(String[] args) {
        System.out.println("1 - start contract");
        System.out.println("2 - pay contract");
        System.out.println("3 - view contract");
        System.out.println("4 - end contract");
        switch (args[0]) {
            case "1":
                Payment start = new Paypal();
                start.startContract();
                break;
            case "2":
                Payment pay = new Paypal();
                pay.payContract();
                break; 
            case "3":
                Payment view = new Paypal();
                view.viewContract();
                break;
            case "4":
                Payment end = new Paypal();
                end.endContract();
                break;
            default:
                System.out.println("Invalid option");
                break;
        }
    }

    
}