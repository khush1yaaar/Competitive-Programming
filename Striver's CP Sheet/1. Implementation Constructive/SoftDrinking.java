import java.util.*;

public class SoftDrinking {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int l = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        int p = sc.nextInt();
        int nl = sc.nextInt();
        int np = sc.nextInt();

        int drink = (k * l) / nl;
        int slices = c * d;
        int salt = p / np;

        int min_drinks = Math.min(drink, Math.min(slices, salt));

        int min_rounds = min_drinks / n;

        System.out.println(min_rounds);
        sc.close();
    }
}
