import java.util.Scanner;

public class Contador {

    static Scanner scanf = new Scanner(System.in);
    static int numero1;
    static int numero2;

    public static void main(String[] args) {
        System.out.println("Digite dois números inteiros: ");
        numero1 = scanf.nextInt();
        numero2 = scanf.nextInt();
        try {
            verificaNumero(numero1, numero2);
        } catch (IllegalArgumentException e) {
            System.out.println("Erro: " + e.getClass().getName() + " - " + e.getMessage());
            return;
        }
        for (int i = numero1; i <= numero2; i++) {
            System.out.println(i);
        }
    }

    //verifica se o numero2 é maior que o numero1
    //se nao for, trowa uma exceção
    public static void verificaNumero(int numero1, int numero2) {
        if (numero2 < numero1) {
            throw new IllegalArgumentException("O segundo número deve ser maior que o primeiro");
        } else {
            System.out.println("O segundo número é maior que o primeiro");
        }
    }
}
