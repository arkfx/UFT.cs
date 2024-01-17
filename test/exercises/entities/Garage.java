package test.exercises.entities;

public class Garage{

    private static int MAXCAPACITY = 150;
    private static int MAXTYPE = 25;
    private int currentCapacity;
    private int currentTypes;

    public Garage() {
    }

    public static int getMAXCAPACITY() {
        return MAXCAPACITY;
    }

    public static int getMAXTYPE() {
        return MAXTYPE;
    }

    public int getCurrentCapacity() {
        return currentCapacity;
    }

    public int getCurrentTypes() {
        return currentTypes;
    }

    public void setCurrentTypes() {
        currentTypes += 1;
    }

    public boolean currentCapacity(Integer quantity) {
        if(quantity > MAXCAPACITY - currentCapacity) {
            System.out.println("Quantidade excede a capacidade máxima");
            return true;
        } else {
            currentCapacity += quantity;
            return false;
        }
    }

}