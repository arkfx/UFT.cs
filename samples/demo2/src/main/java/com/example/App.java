package samples.demo2.src.main.java.com.example;
import java.util.InputMismatchException;
import java.util.Scanner;
import samples.demo2.src.main.java.com.example.entities.Individual;
import samples.demo2.src.main.java.com.example.entities.Legal;
import samples.demo2.src.main.java.com.example.entities.Person;

/**
 * Hello world!
 *
 */



public class App {
    static Scanner input = new Scanner(System.in);
    
    public static void main( String[] args ) {
        System.out.println( "Hello World!" );
    }

    public static void menu() {
        System.out.println()

        System.out.println("1 - Individual");
        System.out.println("2 - Legal");
        System.out.println("3 - Sair");
        System.out.print("Digite a opção desejada: ");



    }

    public static void insertIndividual() {
        Scanner input = new Scanner(System.in);

        System.out.println("Digite o nome: ");
        String name = input.nextLine();

        Double yIncome = validInput("Digite a renda anual: ");

        System.out.println("Digite os gastos com saúde: ");
        Double healthExpenditures = input.nextDouble();

        Individual individual = new Individual(name, yIncome, healthExpenditures);
        individual.setTaxPaid(individual.CalcTax());

        System.out.println("Taxa a ser paga: " + individual.getTaxPaid());
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



}
