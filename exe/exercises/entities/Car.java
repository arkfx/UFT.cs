package exe.exercises.entities;

public class Car {

    private Integer id;
    private Integer color;
    private Integer quantity;

    public Car() {
    }

    public Car(int id, int color, int quantity) {
        this.id = id;
        this.color = color;
        this.quantity = quantity;
    }

    public int getId() {
        return id;
    }
    
    public void setId(Integer id) {
        this.id = id;
    }

    public int getColor() {
        return color;
    }

    public void setColor(Integer color) {
        this.color = color;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(Integer quantity) {
        this.quantity = quantity;
    }

    public void verifyType(Integer id, Integer color, Integer quantity, Garage garage, Car[] cars) {
        for (int i = 0; i < garage.getCurrentTypes(); i++) {
            if (id == cars[i].getId() && color == cars[i].getColor()) {
                cars[i].setQuantity(cars[i].getQuantity() + quantity);
                return;
            }
        }
        cars[garage.getCurrentTypes()] = new Car(id, color, quantity);
        return;   
    }
}