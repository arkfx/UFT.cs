package uft.edu.draft;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;


/**
 * Hello world!
 *
 */
public class AppDraft 
{
    //create a constant
    public static final double PI = 3.14159;
    


    public static void main( String[] args )
    {
        //declare variables
        byte idade = 127;
        Short idadeshort = 32767;
        Integer idadeInt = 2147483647;
        double cpf = 098765432109D;
        short numeroCurto = 1;
        int numeroNormal = numeroCurto;

        DateTimeFormatter formato = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate data = LocalDate.parse("01/02/2023", formato);
        String sdf = data.format(formato);

        //print variables
        System.out.println( "Hello World!" );
        System.out.println(idade);
        System.out.println(idadeshort);
        System.out.println(idadeInt);
        System.out.println(cpf);
        System.out.println(numeroCurto);
        System.out.println(numeroNormal);

        System.out.println(sdf);

        System.out.println(PI);

        operadoresRelacionais();
        operadoresLogicos();
    }

    public static void operadoresRelacionais() {

        System.out.println("Operadores Relacionais");

        int a = 10;
        int b = 20;
        int c = 10;

        /* System.out.println(a == b);
        System.out.println(a == c);
        System.out.println(a != b);
        System.out.println(a != c);
        System.out.println(a > b);
        System.out.println(a < b);
        System.out.println(a >= b);
        System.out.println(a <= b); */

        //agora com strings

        System.out.println("Comparando strings");

        String nome1 = "JAVA";
        String nome2 = "JAVA";

        String nome3 = new String("JAVA");
        
        System.out.println(nome1 == nome2); //true - compara a referência
        System.out.println(nome1 == nome3); //false - compara a referência
        System.out.println(nome1.equals(nome3)); //true - compara o conteúdo

        //agora com inteiros

        System.out.println("Comparando inteiros");

        Integer num1 = 100;
        Integer num2 = 100;
        int num3 = 100;
        int num4 = 100;

        Integer num5 = 1000;
        Integer num6 = 1000;

        System.out.println(num1 == num2); //true - compara a referência (armazenamento em cache)
        System.out.println(num1 == num3); //true - compara a referência
        System.out.println(num1 == num4); //true - compara a referência

        System.out.println(num4 == num1); //true - compara o conteúdo
        System.out.println(num4 == num2); //true - compara o conteúdo
        System.out.println(num4 == num3); //true - compara o conteúdo

        System.out.println(num5 == num6); //false - compara a referência (não armazenamento em cache)

    }

    public static void operadoresLogicos() {

        System.out.println("Operadores Lógicos");

        boolean a = true;
        boolean b = false;

        System.out.println(a && b); //false
        System.out.println(a || b); //true
        System.out.println(!a); //false
        System.out.println(!b); //true

    }

    public static void metodos(){
        System.out.println("Métodos");
    }
}