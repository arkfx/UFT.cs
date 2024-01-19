package com.example;

import java.util.InputMismatchException;
import java.util.Scanner;

import com.example.entities.Individual;
import com.example.entities.Legal;
import com.example.entities.Person;

public class App {
    static Scanner input = new Scanner(System.in);
    
    public static void main( String[] args ) {
        menu();
    }

    public static void menu() {
        System.out.println("\nSelecione o tipo de pessoa:\n");

        System.out.println("1 - Individual");
        System.out.println("2 - Legal");
        System.out.println("3 - Relatorio: ");
        System.out.println("4 - Finalizar.\n");
        double resp = validInput("\n\tDigite a opção desejada: ");
        int resp2 = (int) resp; //maior gambiarra da historia

        switch(resp2) {

            case 1:
                insertIndividual();
                break;

            case 2:
                insertLegal();
                break;

            case 3:
                report();
                break;

            case 4:
                exitProgram();
                break;
        }
        
        menu();
    }

    public static void insertIndividual() {


        System.out.print("\n\tDigite o nome: ");
        input.nextLine();
        String name = input.nextLine();
        
        Double yIncome = validInput("\n\tDigite a renda anual: ");

        Double healthExpenditures = validInput("\n\tDigite os gastos com saúde: ");
        
        Individual individual = new Individual(name, yIncome, healthExpenditures);

        individual.setTaxPaid(individual.calcTax());

    }

    public static void insertLegal() {

        System.out.println("\n\tDigite o nome: ");
        input.nextLine();
        String name = input.nextLine();

        Double yIncome = validInput("\n\tDigite a renda anual: ");
        Integer numbersEmployees = (int) validInput("\n\tDigite o número de funcionários: ");

        Legal legal = new Legal(name, yIncome, numbersEmployees);
 
        legal.setTaxPaid(legal.calculateTax());

    }


    public static void report() {

        if (Person.getList().isEmpty()) {
            System.out.println("\nNenhum imposto foi pago ainda.\n");
            return;
        }

        System.out.println("\nRelatório de impostos pagos:\n");

        for (Person person : Person.getList()) {
            System.out.println(person);
        }

        System.out.println("\nTotal de impostos pagos: " + String.format("%.2f", Person.calcTotalTax()));

    }




    public static double validInput(String print) {
        double entry;
        do{
            System.out.print(print);
            entry = 0;
            
            try {   //tenta converter a entrada para int
                entry = input.nextDouble();
                if (entry < 0) {
                    System.out.println("\nValor negativo, tente novamente.\n" );
                    entry = 0;
                }
            } catch (InputMismatchException e) {    //caso não seja possível
                char codeChar = input.next().charAt(0); //pega o primeiro caractere da entrada

                if(codeChar == '/') {   // caso o usuário digite '/', volta ao menu
                    menu();
                }
            
                //caso não converteu a entrada para int e o usuario não digitou '/', retorna mensagem de erro
                System.out.print("\nEntrada inválida, tente novamente.\n" );
                input.nextLine();   //buffer do teclado
            }
        }while (entry == 0);    //enquanto a entrada for 0, continua pedindo uma entrada válida
        
        return entry;
    }

    
    public static void exitProgram() {
        System.out.print("\n\nFinalizando programa");
        for (int i = 0; i < 3; i++) {
            try {
                Thread.sleep(1000);
                System.out.print(".");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.exit(0);
    }

    
}




