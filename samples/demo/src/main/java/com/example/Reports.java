package com.example;
import java.util.Scanner;

public class Reports {

    public static void report() {
        System.out.println("1 - Relatório geral");
        System.out.println("2 - Relatório por cor");
        System.out.println("3 - Relatório por código");
        System.out.println("4 - Busca por veículo");

        Scanner input = new Scanner(System.in);
        int resp = input.nextInt();

        switch (resp) {
            case 1:
                Reports.generalReport();
                return;
            case 2:
                //Reports.colorReport();
                return;
            case 3:
                //Reports.codeReport();
                return;
            case 4:
                //Reports.searchReport();
                return;
            default:
                System.out.println("Opção inválida");
                break;
        }
        Reports.report();
    }

    public static void generalReport() {
        System.out.println("Relatório geral");
        System.out.println("Quantidade total de veículos: " + Garagem.current_capacity);
        System.out.println("Percentual de ocupação da gara: " + (Garagem.current_capacity / Garagem.max_capacity) * 100 + "%");
        for (int i = 0; i < Garagem.cars.length; i++) {
            if (Garagem.cars[i].quantity > 0) {
                System.out.println("id: " + Garagem.cars[i].id);
                System.out.println("cor: " + Garagem.cars[i].color);
                System.out.println("quantidade: " + Garagem.cars[i].quantity);
            }
        }
    }
}
