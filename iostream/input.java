/* faça um programa que leia uma matriz 10x4 de números inteiros e salve esta matriz em um arquivo binário chamado testmatriz.
Faça então outro programa que abra o arquivo testmatriz e coloque os valores contidos nele em uma outra matriz 10x4.  */

public class input {
    public static void main(String[] args) {
        System.out.println("INPUT");

        //new line
        System.out.println();
        System.out.println();

        //declara a matriz
        int[][] matriz = new int[10][4];

        //preenche a matriz com o input do usuário
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 4; j++){
                //System.out.print("Digite o valor da posição [" + i + "][" + j + "]: ");
                //matriz[i][j] = Integer.parseInt(System.console().readLine());

                //random minumin 10 and maximum 100
                matriz[i][j] = (int)(Math.random() * 90) + 10;
            }
        
        }

        //create the file testmatriz
        java.io.File file = new java.io.File("testmatriz.txt");

        //write the matriz in the file
        try(java.io.PrintWriter output = new java.io.PrintWriter(file);){
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 4; j++){
                    output.print(matriz[i][j] + " ");
                }
                output.println();
            }
        }catch(java.io.FileNotFoundException ex){
            System.out.println("File not found");
        }
    }
}
