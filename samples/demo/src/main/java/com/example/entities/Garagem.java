package com.example.entities;
import com.example.App;

public class Garagem {
    public static int current_capacity = 0;
    public static int max_capacity = 150;
    public static int max_type = 25;

    public static class Car {
        public int id = 0;
        public int color = 0;
        public int quantity = 0;
    }
    //array of objects
    public static Car cars[] = new Car[max_type];
    
    public static void insert(){
        if (current_capacity >= max_capacity) {
            System.out.println("\nGaragem cheia.\n");
            return;
        }

        System.out.println("\n\n---Inserir veículo---\n");

        int id = 0;
        id = App.validInput("\n\tId do carro: ");

        int color = App.validInput("\n\n\tCódigo da cor do carro: \n\n\t 1 - Branco \n\t 2 - Preto \n\t 3 - Vermelho \n\t 4 - Cinza: ");

        int quantity = App.validInput("\n\tQuantidade: ");

        if (current_capacity + quantity > max_capacity) {
            System.out.println("\nCapacidade maxima atingida.");
            return;
        }

        for (int i = 0; i < cars.length; i++) {
            if (cars[i].id == id && cars[i].color == color) {
                cars[i].quantity += quantity;
                current_capacity += quantity;
                System.out.println("\nQuantidade adicionada!");
                return;
            }
        }
        for (int i = 0; i < cars.length; i++) {
            if (cars[i].quantity == 0) {
                cars[i].id = id;
                cars[i].color = color;
                cars[i].quantity = quantity;
                current_capacity += quantity;
                System.out.println("\nCarro adicionado\n");
                return;
            }
        }
        System.out.println("\nLimite de tipos de carros atingido.\n");
        return;
    }

    public static void remove(){
        if (current_capacity == 0) {
            System.out.println("\nGaragem vazia.\n");
            return;
        }

        System.out.println("\n\n---Remover veículo---\n");

        int id = App.validInput("\nId do carro: ");

        int color = App.validInput("\n\nCódigo da cor do carro: \n\n 1 - branco \n 2 - preto \n 3 - vermelho \n 4 - cinza: ");

        for (int i = 0; i < cars.length; i++) {
            if (cars[i].id == id && cars[i].color == color) {
                System.out.println("\n\tQuantidade atual: " + cars[i].quantity);
                System.out.println("\nQuantidade a ser removida: ");
                int quantity = App.validInput("\n\tQuantidade: ");

                if (quantity > cars[i].quantity) {
                    System.out.println("\nQuantidade inserida maior que a atual.\n");
                    return;
                }
                cars[i].quantity -= quantity;
                current_capacity -= quantity;
                System.out.println("Carro removido");
                return;
            }
        }
        System.out.println("\nTipo de Carro não encontrado.\n");
        return;
    }

}