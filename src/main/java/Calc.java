public class Calc {

    public static String calculate ( double a, double b, double c, double d, double e, double f){

        if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0)) {

            System.out.print("5");
            return "5";

        } else if ((a * d - c * b != 0) && ((e * d - b * f != 0) || (a * f - c * e != 0))) {

            double y = (a * f - c * e) / (a * d - c * b);

            double x = (d * e - b * f) / (d * a - b * c);

            System.out.print("2 " + x + " " + y);
            return "2";

        } else if (((a * d - c * b == 0) && ((e * d - b * f != 0) || (a * f - c * e != 0))) ||

                (a == 0 && c == 0 && e / b != f / d) ||

                (b == 0 && d == 0 && e / a != f / c) ||

                (a == 0 && b == 0 && c == 0 && d == 0 && (e / f > 0))) {

            if (((a == 0 && b == 0 && e == 0 && d != 0 && c == 0) ||

                    (c == 0 && d == 0 && f == 0 && b != 0 && a == 0))) {

                double y = -1.1;

                if (b == 0)

                    y = f / d;

                else if (d == 0)

                    y = e / b;

                else if (e == 0 || f == 0)

                    y = 0;

                System.out.print("4 " + y);
                return "4.1";

            } else if (((a == 0 && b == 0 && e == 0 && c != 0 && d == 0) ||

                    (c == 0 && d == 0 && f == 0 && a != 0 && b == 0))) {

                double x = -1.1;

                if (a == 0)

                    x = f / c;

                else if (c == 0)

                    x = e / a;

                else if (e == 0 || f == 0)

                    x = 0;

                System.out.print("3 " + x);
                return "3.1";

            } else {

                System.out.print("0");
                return "0";
            }

        } else if (a == 0 && c == 0) {

            double y;

            if (e == 0)

                y = f / d;

            else if (f == 0)

                y = e / b;

            else

                y = e / b;

            System.out.print("4 " + y);
            return "4.2";

        } else if (b == 0 && d == 0) {

            double x;

            if (e == 0)

                x = f / c;

            else if (f == 0)

                x = e / a;

            else

                x = e / a;

            System.out.print("3 " + x);
            return "3.2";

        } else if (b == 0 && e == 0) {

            double k, n;

            k = -c / d;

            n = f / d;

            System.out.print("1 " + k + " " + n);
            return "3.3";

        } else if (d == 0 && f == 0) {

            double k, n;

            k = -a / b;

            n = e / b;

            System.out.print("1 " + k + " " + n);
            return "1.1";

        } else if (a == 0 && e == 0) {

            double k, n;

            k = -d / c;

            n = f / c;

            System.out.print("1 " + k + " " + n);
            return "1.2";

        } else if (c == 0 && f == 0) {

            double k, n;

            k = -b / a;

            n = e / a;

            System.out.print("1 " + k + " " + n);
            return "1.3";

        } else if ((a / b == c / d)) {

            double k, n;

            k = -c / d;

            n = f / d;

            System.out.print("1 " + k + " " + n);
            return "1.4";

        } else {

            System.out.print("Are u kidding me?");
            return "99";

        }
    }

}
