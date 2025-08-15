import java.util.*;

public class TwoKnights {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int k = 1; k <= n; k++) {
            long curr =  ((long) Math.pow(k, 2) * ((long) Math.pow(k, 2) - 1) / 2) - 4 * (k - 1) * (k - 2);

            System.out.println(curr);
        }
        sc.close();
    }
}