import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        double a, b, c, d, e, f;
        Scanner scan = new Scanner(System.in);
        a = scan.nextDouble();
        b = scan.nextDouble();
        c = scan.nextDouble();
        d = scan.nextDouble();
        e = scan.nextDouble();
        f = scan.nextDouble();

        Calc.calculate(a,b,c,d,e,f);
    }

}
