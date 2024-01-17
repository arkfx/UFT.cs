package com.example;
import java.util.Scanner;

public class Garagem {
    public static int current_capacity = 0;
    public static int max_capacity = 150;
    public static int max_type = 25;

    public class Car {
        public int id = 0;
        public int color = 0;
        public int quantity = 0;
    }
    //array of objects
    public static Car cars[] = new Car[max_type];

    public static void insert(){
        if (current_capacity >= max_capacity) {
            System.out.println("Garagem cheia");
            return;
        }
        Scanner input = new Scanner(System.in);

        System.out.println("id do carro: ");
        int id = input.nextInt();

        System.out.println("codigo da cor do carro: \t 1 - branco \t 2 - preto \t 3 - vermelho \t 4 - cinza: ");
        int color = input.nextInt();

        System.out.println("quantidade: ");
        int quantity = input.nextInt();

        if (current_capacity + quantity > max_capacity) {
            System.out.println("capacidade maxima atingida");
            return;
        }

        for (int i = 0; i < cars.length; i++) {
            if (cars[i].id == id && cars[i].color == color) {
                cars[i].quantity += quantity;
                current_capacity += quantity;
                System.out.println("Carro adicionado");
                return;
            }
        }
        for (int i = 0; i < cars.length; i++) {
            if (cars[i].quantity == 0) {
                cars[i].id = id;
                cars[i].color = color;
                cars[i].quantity = quantity;
                current_capacity += quantity;
                System.out.println("Carro adicionado");
                return;
            }
        }
        System.out.println("limite de tipos de carros atingido");
        return;
    }

    public static void remove(){
        Scanner input = new Scanner(System.in);

        System.out.println("id do carro: ");
        int id = input.nextInt();

        System.out.println("codigo da cor do carro: \t 1 - branco \t 2 - preto \t 3 - vermelho \t 4 - cinza: ");
        int color = input.nextInt();

        for (int i = 0; i < cars.length; i++) {
            if (cars[i].id == id && cars[i].color == color) {
                System.out.println("quantidade atual: " + cars[i].quantity);
                System.out.println("quantidade a ser removida: ");
                int quantity = input.nextInt();
                if (quantity > cars[i].quantity) {
                    System.out.println("quantidade inserida maior que a atual");
                    return;
                }
                cars[i].quantity -= quantity;
                current_capacity -= quantity;
                System.out.println("Carro removido");
                return;
            }
        }
        System.out.println("tipo de Carro não encontrado");
        return;
    }
}