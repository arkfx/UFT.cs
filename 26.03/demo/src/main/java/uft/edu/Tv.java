package uft.edu;

public class Tv {
    
    private boolean ligada;
    private int canal;
    private int volume;
    
    public Tv() {
        ligada = false;
        canal = 1;
        volume = 0;
    }

    public void ligar() {
        ligada = true;
    }
    public void desligar() {
        ligada = false;
    }
    public void aumentarVolume() {
        volume++;
    }
    public void diminuirVolume() {
        volume--;
    }
    public void aumentarCanal() {
        canal++;
    }
    public void diminuirCanal() {
        canal--;
    }
    public void trocarCanal(int novoCanal) {
        canal = novoCanal;
    }
    public void printarEstado() {
        System.out.println("Ligada: " + ligada);
        System.out.println("Canal: " + canal);
        System.out.println("Volume: " + volume);
    }  

}

