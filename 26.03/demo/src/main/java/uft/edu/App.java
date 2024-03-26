package uft.edu;
import java.util.Scanner;

public class App {

    public static void main(String[] args) {
        Tv televisao = new Tv();
        Scanner scanner = new Scanner(System.in);

        System.out.println("1 - Ligar");
        System.out.println("2 - Desligar");
        System.out.println("3 - Aumentar volume");
        System.out.println("4 - Diminuir volume");
        System.out.println("5 - Aumentar canal");
        System.out.println("6 - Diminuir canal");
        System.out.println("7 - Trocar canal");
        System.out.println("8 - printar o estado da televisão");
        System.out.println("9 - Sair");
        
        int opcao = 0;
        while (opcao != 9) {
            System.out.println("Digite a opção desejada:");
            opcao = scanner.nextInt();
            switch (opcao) {
                case 1:
                    televisao.ligar();
                    break;
                case 2:
                    televisao.desligar();
                    break;
                case 3:
                    televisao.aumentarVolume();
                    break;
                case 4:
                    televisao.diminuirVolume();
                    break;
                case 5:
                    televisao.aumentarCanal();
                    break;
                case 6:
                    televisao.diminuirCanal();
                    break;
                case 7:
                    System.out.println("Digite o novo canal:");
                    int novoCanal = scanner.nextInt();
                    televisao.trocarCanal(novoCanal);
                    break;
                case 8:
                    televisao.printarEstado();
                    break;
                case 9:
                    System.out.println("Saindo...");
                    scanner.close();
                    break;
                default:
                    System.out.println("Opção inválida");
            }
        }
        
    }
}