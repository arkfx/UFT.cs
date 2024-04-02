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
     * Liga a TV se ela estiver desligada. Se já estiver ligada, imprime uma mensagem.
     */
    public void ligar() {
        if(!ligada)
            ligada = true;
        else
            System.out.println("tv já ligada");
    }
    
    /**
     * Desliga a TV se ela estiver ligada. Se já estiver desligada, imprime uma mensagem.
     */
    public void desligar() {
        if(ligada)
            ligada = false;
        else
            System.out.println("tv já está desligada");
    }
    
    /**
     * Aumenta o volume da TV em uma unidade se a TV estiver ligada e o volume for menor que 100.
     * Caso contrário, imprime uma mensagem adequada.
     */
    public void aumentarVolume() {
        if(ligada)
            if(volume < 100)
                volume++;
            else
                System.out.println("tv já está no maior volume");
        else
            System.out.println("tv precisa estar ligada");
    }
    
    /**
     * Diminui o volume da TV em uma unidade se a TV estiver ligada e o volume for maior que 1.
     * Caso contrário, imprime uma mensagem adequada.
     */
    public void diminuirVolume() {
        if(ligada)
            if(volume > 1)
                volume--;
            else
                System.out.println("tv já está no menor volume");
        else
            System.out.println("tv precisa estar ligada");
    }
    
    /**
     * Aumenta o canal da TV em uma unidade se a TV estiver ligada e o canal for menor que 1000.
     * Caso contrário, imprime uma mensagem adequada.
     */
    public void aumentarCanal() {
        if(ligada)
            if(canal < 1000)
                canal++;
            else    
                System.out.println("tv ja está no maior canal");
        else
            System.out.println("tv precisa estar ligada");
    }
    
    /**
     * Diminui o canal da TV em uma unidade se a TV estiver ligada e o canal for maior que 1.
     * Caso contrário, imprime uma mensagem adequada.
     */
    public void diminuirCanal() {
        if(ligada)
            if(canal > 1)
                canal--;
            else
                System.out.println("tv já está no menor canal");
        else
            System.out.println("tv precisa estar ligada"); 
    }
    
    /**
     * Troca o canal da TV para o canal especificado se a TV estiver ligada, o canal for diferente do atual e estiver entre 1 e 100.
     * Caso contrário, imprime uma mensagem adequada.
     * @param novoCanal O novo canal para o qual a TV deve ser trocada.
     */
    public void trocarCanal(int novoCanal) {
        if(ligada)
            if(novoCanal < 100 || novoCanal > 1)
                if(novoCanal != canal)
                    canal = novoCanal;
                else
                    System.out.println("canal já selecionado");
            else
                System.out.println("canal digitado invalido");
        else
            System.out.println("tv precisa estar ligada"); 
    }
    
    /**
     * Imprime o estado atual da TV, incluindo se está ligada ou desligada, o canal atual e o volume atual.
     */
    public void printarEstado() {
        System.out.println("Ligada: " + ligada);
        System.out.println("Canal: " + canal);
        System.out.println("Volume: " + volume);
    }

    /**
     * Retorna o estado atual da TV, se está ligada ou desligada.
     * @return boolean - true se a TV estiver ligada, false se estiver desligada.
     */
    public boolean returnLigada(){
        return ligada;
    }

    /**
     * Retorna o canal atual da TV.
     * @return int - o canal atual da TV.
     */
    public int returnCanal(){
        return canal;
    }

    /**
     * Retorna o volume atual da TV.
     * @return int - o volume atual da TV.
     */
    public int returnVolume(){
        return volume;
    }

}