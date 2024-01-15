package workspaces.UFT.cs.application;

import java.util.Scanner;
import UFT.cs.entities.Car;
import UFT.cs.entities.Garage;

 
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
    destes relatórios: Relatório geral (mostre todos os veículos e seus dados, a quantidade total de
    veículos e a percentagem de ocupação das garagens), relatório por cor (dada a cor, mostre a
    quantidade total e todos os veículos desta cor), relatório por código (dado o código, mostre a
    quantidade total e todos os veículos com o código e seus dados), busca por veículo (Dados o
    código do veículo e sua cor, mostre a quantidade. Se o veículo for encontrado, a busca deve ser
    interrompida). Pode ocorrer a necessidade de cadastrar um veículo que tenha sido adquirido
    esporadicamente, então o programa deve ser capaz de inserir um veículo (apenas 1) a qualquer
    momento.  */

public class Main {

    public static void main(String[] args) {
        
        Garage garage = new Garage();
        Car[] cars = new Car[garage.getMAXTYPE];

        readData(cars);    
        
    }



    public static void readData(Car[] cars) {
        Scanner input = new Scanner(System.in);
        int resp;
       do {    
        
            if (getcurrentCapacity() >= getMAXCAPACITY()) {
                System.out.println("Capacidade máxima atingida");
                break;
            }
            
            boolean verify = false;
            do{
                System.out.println("digite a quantidade de veículos a serem cadastrados");
                int quantity = input.nextInt();
                verify = currentCapacity(quantity);
            }while(verify);
            
            
            System.out.print("digite o id do carro ");
            int id = input.nextInt();

            System.out.print("Digite o código da cor do carro (1 - Branco / 2 - Preto / 3 - Vermelho / 4 - Cinza) --> ");
            int color = input.nextInt();

            verifyType(id, color, quantity);



            System.out.print("Deseja adicionar outro veículo ? (1 - sim / 0 - não) --> ");
            resp = input.nextInt();

            
       } while (resp != 0);

    }
    
    /* public static int validInput(Scanner input) {
        int entry = 0;
        try {   //tenta converter a entrada para int
            entry = input.nextInt();
        } catch (InputMismatchException e) {    //caso não seja possível
            
            System.out.print(RED + "\n\tEntrada inválida, tente novamente.\n" + RESET);
            input.nextLine();   //buffer do teclado
        }
        return entry;
    } */
}