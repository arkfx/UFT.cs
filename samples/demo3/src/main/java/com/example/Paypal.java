package com.example;


class Paypal implements Payment {
    public void startContract() {
        System.out.println("Starting contract");
    }
    public void payContract() {
        System.out.println("Paying contract");
    }
    public void viewContract() {
        System.out.println("Viewing contract");
    }
    public void endContract() {
        System.out.println("Ending contract");
    }

}
