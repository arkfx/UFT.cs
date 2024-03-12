package com.example;

class paypal implements Payment {
    void startContract() {
        System.out.println("Starting contract");
    }
    void payContract() {
        System.out.println("Paying contract");
    }
    void viewContract() {
        System.out.println("Viewing contract");
    }
    void endContract() {
        System.out.println("Ending contract");
    }

}
