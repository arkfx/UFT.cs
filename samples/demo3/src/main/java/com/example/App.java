package com.example;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {   
        menu();
    }


public static void menu() {
    System.out.println("Welcome to the payment system");
    System.out.println("Please select an option:");
    System.out.println("1. Pay via Paypal"); //1% for each installment + 2% per payment
    System.out.println("2. Pay via Google Pay"); //0 fee + 1% if its international
    System.out.println("3. Pay via Bitcoin"); //https://api.blockchain.info/mempool/fees
}
}
    
