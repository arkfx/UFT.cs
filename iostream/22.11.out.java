/* faça um programa que leia uma matriz 10x4 de números inteiros e salve esta matriz em um arquivo binário chamado testmatriz.
Faça então outro programa que abra o arquivo testmatriz e coloque os valores contidos nele em uma outra matriz 10x4.  */

public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("OUTPUT");

        System.out.println();
        System.out.println();

        //declara a matriz
        int[][] matriz = new int[10][4];

        //le arquivo "testmatriz"
        java.io.FileInputStream fis = new java.io.FileInputStream("testmatriz");

        //le a matriz a partir do arquivo
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 4; j++)
                matriz[i][j] = fis.read();
        }

    }
}
