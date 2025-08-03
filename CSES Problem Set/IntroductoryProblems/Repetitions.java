import java.util.*;

public class Repetitions {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String dna = sc.nextLine();
        int count = 1;
        int max = 1;

        for(int i = 1; i < dna.length(); i++) {
            if(dna.charAt(i) != dna.charAt(i - 1)) {
                count = 1;
            }

            else {
                count++;
            }
            max = Math.max(max, count);
        }

        System.out.println(max);

        sc.close();
    }
}
