package com.example;

import java.util.Arrays;
import java.util.Scanner;
import java.util.InputMismatchException;

import com.example.entities.Garagem;
import com.example.entities.Reports;


/* Uma concessionária de veículos mantêm o cadastro de seus veículos desta forma:
    código do veículo (número inteiro),
    código da cor (número inteiro, 1 para branco, 2 para preto, 3 para vermelho e 4 para cinza),
    quantidade.

    A capacidade máxima de armazenagem nas suas garagens é de 150 veículos. Não permita que
    sejam cadastrados mais veículos do que a capacidade.

    Faça um programa que inicialmente leia os dados dos vários veículos que estão atualmente na
    concessionária. Serão cadastrados, no máximo 25 tipos de veículos. Não permita código do veículo
    com mesma cor em linhas diferentes.

    Após esta leitura inicial, ofereça ao vendedor, sempre que desejar, a possibilidade de consultar um
    destes relatórios:

    Relatório geral (mostre todos os veículos e seus dados, a quantidade total de veículos e a percentagem de ocupação das garagens), 

    relatório por cor (dada a cor, mostre a quantidade total e todos os veículos desta cor),

    relatório por código (dado o código, mostre a quantidade total e todos os veículos com o código e seus dados),

    busca por veículo (Dados o código do veículo e sua cor, mostre a quantidade. 
    Se o veículo for encontrado, a busca deve ser interrompida). 

    Pode ocorrer a necessidade de cadastrar um veículo que tenha sido adquirido
    esporadicamente, então o programa deve ser capaz de inserir um veículo (apenas 1) a qualquer
    momento.  */

public class App {
    private static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
        Arrays.setAll(Garagem.cars, i -> new Garagem.Car());
        App.menu();
    }

    //main menu
    public static void menu() {
        System.out.println("\n\n\n");
        System.out.println("1 - Inserir veículo");
        System.out.println("2 - Remover quantidade de veículos");
        System.out.println("3 - Relatórios");   
        System.out.println("4 - Sair");

        int resp = validInput("\nDigite a opção desejada: ");
        switch (resp) {
            case 1:
                Garagem.insert();
                break;
            case 2:
                Garagem.remove();
                break;
            case 3:
                Reports.report();
                break;
            case 4:
                exitProgram();
                input.close();
                return;
            default:
                System.out.println("\nOpção inválida");
                break;
        }
        menu();
    }

     public static int validInput(String print) {
        int entry;
        do{
            System.out.print(print);
            entry = 0;
            
            try {   //tenta converter a entrada para int
                entry = input.nextInt();
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
