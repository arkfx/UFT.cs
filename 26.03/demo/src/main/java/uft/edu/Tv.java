package uft.edu;

public class Tv {
    
    private boolean ligada;
    private int canal;
    private int volume;
    
    /**
     * Construtor padrão da classe Tv.
     * Inicializa a TV desligada, no canal 1 e com volume 0.
     */
    protected Tv() {
        ligada = false;
        canal = 1;
        volume = 0;
    }
    
    /**
     * Liga a TV.
     */
    public void ligar() {
        ligada = true;
    }
    
    /**
     * Desliga a TV.
     */
    public void desligar() {
        ligada = false;
    }
    
    /**
     * Aumenta o volume da TV em uma unidade.
     */
    public void aumentarVolume() {
        volume++;
    }
    
    /**
     * Diminui o volume da TV em uma unidade.
     */
    public void diminuirVolume() {
        volume--;
    }
    
    /**
     * Aumenta o canal da TV em uma unidade.
     */
    public void aumentarCanal() {
        canal++;
    }
    
    /**
     * Diminui o canal da TV em uma unidade.
     */
    public void diminuirCanal() {
        canal--; 
    }
    
    /**
     * Troca o canal da TV para o canal especificado.
     * @param novoCanal O novo canal para o qual a TV deve ser trocada.
     */
    public void trocarCanal(int novoCanal) {
        canal = novoCanal;
    }
    
    /**
     * Imprime o estado atual da TV, incluindo se está ligada ou desligada, o canal atual e o volume atual.
     */
    public void printarEstado() {
        System.out.println("Ligada: " + ligada);
        System.out.println("Canal: " + canal);
        System.out.println("Volume: " + volume);
    }  

}