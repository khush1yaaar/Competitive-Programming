import java.util.*;

public class InSearchofanEasyProblem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] opinions = new int[n];
        String result = "EASY";
        for(int i = 0; i < n; i++) {
            opinions[i] = sc.nextInt();
        }

        for(int i = 0; i < n; i++) {
            if(opinions[i] == 1) {
                result = "HARD";
            }
        }

        System.out.println(result);
        sc.close();
    }
}
