package foo;

public class Foo {

    public static void main(String[] args) {
        
        int x = 0;
        for(int i = 1; i <= 3; i++){
            int s = i*i;
            x += s;
        }
        System.out.println(x);
    }
    
}
