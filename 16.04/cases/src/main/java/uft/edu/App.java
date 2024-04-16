package uft.edu;
import java.util.Scanner;

/**
 * Hello world!
 *
 */
public class App 
{
    static int sBase = 2000;
    static Scanner scanf = new Scanner(System.in);
    public static void main( String[] args )
    {
        //create a array of candidatos
        Candidato[] candidatos = new Candidato[10];
        
    }

    public static void analisarCandidato(Candidato[] candidatos) {
        for (int i = 0; i < candidatos.length; i++) {
            System.out.println("Analisando candidato " + i + ": " + candidatos[i].nome);
            if (candidatos[i].salarioPretendido > sBase) {
                System.out.println("ligar para o candidato");
                candidatos[i].status = 1;
            } else if (candidatos[i].salarioPretendido == sBase) {
                System.out.println("ligar para o candidato, com contraprosta");
                candidatos[i].status = 2;
            } else {
                System.out.println("candidato rejeitado");
                candidatos[i].status = 3;
            }
        }
    }

    public static void sortCandidates(Candidato[] candidatos) {
        //sort by salarioPretendido in ascending order
        for (int i = 0; i < candidatos.length; i++) {
            for (int j = i + 1; j < candidatos.length; j++) {
                if (candidatos[i].salarioPretendido > candidatos[j].salarioPretendido) {
                    Candidato temp = candidatos[i];
                    candidatos[i] = candidatos[j];
                    candidatos[j] = temp;
                }
            }
        }
    }
        

    public static void fillData(Candidato[] candidatos) {
        for (int i = 0; i < candidatos.length; i++) {
            System.out.println("Digite o nome do candidato");
            candidatos[i].nome = scanf.nextLine();
            //idade = random int
            candidatos[i].idade = (int) (Math.random() * 100);
            //salarioPretendido = random int
            candidatos[i].salarioPretendido = (int) (Math.random() * 10000);
            //telefone = random int (9 digits)
            candidatos[i].telefone = (int) (Math.random() * 1000000000);
        }
    }

    public static void PrintData(Candidato[] candidatos) {
        for (int i = 0; i < candidatos.length; i++) {
            if (candidatos[i].status == 1 || candidatos[i].status == 2) {
                System.out.println("Nome: " + candidatos[i].nome);
                System.out.println("Idade: " + candidatos[i].idade);
                System.out.println("Salario Pretendido: " + candidatos[i].salarioPretendido);
                System.out.println("Status: " + candidatos[i].status);
            }
        }
    }

    public static void attemptsToContact(Candidato[] candidatos) {
        //max 5 candidates to contact;
        for (int i = 0; i < 5; i++) {
            candidatos[i].nTentativasDeContato = (int) (Math.random() * 5);
        }
        for (int i = 0; i < 5; i++) {
            if (candidatos[i].nTentativasDeContato <= 3) {
                System.out.println("conseguimos entrar em contato com o candidato " + i + "apos " + candidatos[i].nTentativasDeContato + " tentativas");
            } else {
                System.out.println("nao conseguimos entrar em contato com o candidato " + i);
            }
        }
    }

}
