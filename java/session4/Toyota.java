public class Toyota extends Car{

    private String name = "Toyota";

    @Override
     protected void start(){
        System.out.println(name);
    }

    @Override
    protected int checkSpeedStatus(int speed, int limit){
        if(speed > limit){
            return 1;
        }
        else{
            return 0;
        }
    }

    public void extraFunctionality(){
        System.out.println("Toyota = Tank.");
    }
}