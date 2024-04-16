package uft.edu;
import java.util.Scanner;

/**
 * Hello world!
 *
 */
public class App 
{
    static int sBase = 2000;
    public static void main( String[] args )
    {
        Scanner scanf = new Scanner(System.in);
        System.out.println("Digite o valor do salário pretendido: ");
        int sPretendido = scanf.nextInt();
        
        if (sBase > sPretendido) {
            System.out.println("ligar para o candidato");
        } else if (sBase == sPretendido) {
            System.out.println("ligar para o candidato, com contraprosta");
        } else {
            System.out.println("aguardando resultado dos demais candidatos");
        }   
    }
}
