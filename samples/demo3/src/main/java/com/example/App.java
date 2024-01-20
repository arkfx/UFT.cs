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
    System.out.println("3. Pay via Bitcoin"); //https://business-sandbox.cryptopay.me/api/coin_withdrawals/network_fees
    System.out.println("4. Exit");
    System.out.println("Enter your choice: ");
    int choice = Integer.parseInt(System.console().readLine());
    switch (choice) {
        case 1:
            System.out.println("Paypal");
            break;
        case 2:
            System.out.println("Google Pay");
            break;
        case 3:
            System.out.println("Bitcoin");
            break;
        case 4:
            System.out.println("Exit");
            break;
        default:
            System.out.println("Invalid choice");
            break;
        }
        
    }   

}
    
