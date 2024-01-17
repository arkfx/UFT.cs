package com.example.entities;
import com.example.App;

public class Reports {

    public static void report() {

        System.out.println("\n\n\n---Relatórios---.\n\n");
        
        System.out.println("1 - Relatório geral");
        System.out.println("2 - Relatório por cor");
        System.out.println("3 - Relatório por código");
        System.out.println("4 - Busca por veículo");


        int resp = App.validInput("\nDigite a opção desejada: ");

        switch (resp) {
            case 1:
                Reports.generalReport();
                return;
            case 2:
                Reports.colorReport();
                return;
            case 3:
                Reports.codeReport();
                return;
            case 4:
                Reports.searchReport();
                return;
            default:
                System.out.println("Opção inválida");
                break;
        }
        Reports.report();
    }

    public static void generalReport() {
        System.out.println("\n\n\nRelatório geral.\n\n");
        
        System.out.println("\n\tQuantidade total de veículos: " + Garagem.current_capacity);
        System.out.printf("\n\tPercentual de ocupação da garagem: %.2f%%\n", (Garagem.current_capacity * 100.0) / Garagem.max_capacity);
        
        for (int i = 0; i < Garagem.cars.length; i++) {
            if (Garagem.cars[i].quantity > 0) {
                System.out.println("\n\tTipo: " + i+1);
                System.out.println("\n\tId: " + Garagem.cars[i].id);
                System.out.println("\n\tCor: " + Garagem.cars[i].color);
                System.out.println("\n\tQuantidade: " + Garagem.cars[i].quantity);
            }
        }
    }

    public static void colorReport() {
        System.out.println("\n\nRelatório por cor.");
        int color = App.validInput("\n\nCódigo da cor do carro: \n\n 1 - branco \n 2 - preto \n 3 - vermelho \n 4 - cinza: ");
        int total = 0;

        for (int i = 0; i < Garagem.cars.length; i++) {
            if (Garagem.cars[i].color == color) {
                System.out.println("\n\tTipo: " + i+1);
                System.out.println("\n\tId: " + Garagem.cars[i].id);
                System.out.println("\n\tCor: " + Garagem.cars[i].color);
                System.out.println("\n\tQuantidade: " + Garagem.cars[i].quantity);
                total += Garagem.cars[i].quantity;
            }
        }
        if (total == 0) {
            System.out.println("\nNenhum carro encontrado.\n");
        } else {
            System.out.println("\nTotal de carros desta cor: " + total);
        }
    }

    public static void codeReport() {
        System.out.println("Relatório por código");

        System.out.println("Informe o código do veículo --> ");
        int code = App.validInput("\n\tId do carro: ");

        int total = 0;
        for (int i = 0; i < Garagem.cars.length; i++) {
            if (Garagem.cars[i].id == code) {
                System.out.println("\nTipo: " + i+1);
                System.out.println("\nId: " + Garagem.cars[i].id);
                System.out.println("\nCor: " + Garagem.cars[i].color);
                System.out.println("\nQuantidade: " + Garagem.cars[i].quantity);
                total += Garagem.cars[i].quantity;            
            }
        }
        if (total == 0) {
            System.out.println("\nNenhum carro encontrado.\n");
        } else {
            System.out.println("\nTotal de carros deste código: " + total);
        }
    }

    public static void searchReport() {
        System.out.println("\n\nBusca por veículo.\n");
        
        int code = App.validInput("\n\tInforme o código do veículo --> ");

        int color = App.validInput("\n\nInforme o código da cor do carro: \n\n 1 - branco \n 2 - preto \n 3 - vermelho \n 4 - cinza: ");

        for (int i = 0; i < Garagem.cars.length; i++) {
            if (Garagem.cars[i].id == code && Garagem.cars[i].color == color) {
                System.out.println("\n\tTipo: " + i+1);
                System.out.println("\n\tId: " + Garagem.cars[i].id);
                System.out.println("\n\tCor: " + Garagem.cars[i].color);
                System.out.println("\n\tQuantidade: " + Garagem.cars[i].quantity);
                return;
            }
        }
    }
}