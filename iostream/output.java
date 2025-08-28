/* faça um programa que leia uma matriz 10x4 de números inteiros e salve esta matriz em um arquivo binário chamado testmatriz.
Faça então outro programa que abra o arquivo testmatriz e coloque os valores contidos nele em uma outra matriz 10x4.  */

public class output {
    public static void main(String[] args) {
        System.out.println("OUTPUT");

        System.out.println();
        System.out.println();

        //declara a matriz
        int[][] matriz = new int[10][4];

        //le arquivo "testmatriz"
        java.io.File file = new java.io.File("testmatriz.txt");

        //read the file
        try(java.util.Scanner input = new java.util.Scanner(file);){
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 4; j++){
                    matriz[i][j] = input.nextInt();
                }
            }
        }catch(java.io.FileNotFoundException ex){
            System.out.println("File not found");
        }

        //print the matriz
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 4; j++){
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();

        }   
    }
}
