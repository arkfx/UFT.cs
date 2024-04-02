package uft.edu;

import java.util.Scanner;

/**
 * Hello world!
 *
 */
public class App2
{
    public static void main( String[] args )
    {
        Scanner sc = new Scanner(System.in).useLocale(java.util.Locale.US);
        System.out.println("Digite o primeiro número: ");
        double num1 = sc.nextDouble();
        num1 *= 3.5;
        System.out.println("Digite o segundo número: ");
        double num2 = sc.nextDouble();
        num2 *= 7.5;
        double media = (num1 * num2) / 11;
        System.out.println("A soma dos números é: " + media);
    }
}
