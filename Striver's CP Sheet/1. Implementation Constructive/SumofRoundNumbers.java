import java.util.*;

public class SumofRoundNumbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            List<Integer> roundNumbers = new ArrayList<>();
            int place = 0;
            while(n > 0) {
                int digit = n % 10;
                int roundNumber = digit * (int) Math.pow(10, place);
                if(roundNumber > 0) {
                    roundNumbers.add(roundNumber);
                }
                place++;
                n = n / 10;
            }

            System.out.println(roundNumbers.size());
            for(int i = roundNumbers.size() - 1; i >= 0; i--) {
                System.out.print(roundNumbers.get(i));
                if(i > 0) {
                    System.out.print(" ");
                } else {
                    System.out.println();
                }
            }
        }
        sc.close();
    }
}
