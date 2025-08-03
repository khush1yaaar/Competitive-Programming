import java.util.*;

public class BitPP {
    public static int countBit(ArrayList<String> operations) {
        int x = 0;
        for(String op: operations) {
            if(op.charAt(0) == '+' || op.charAt(2) == '+') {
                x++;
            }
            else if(op.charAt(0) == '-' || op.charAt(2) == '-') {
                x--;
            }
        }

        return x;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<String> opereations = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            opereations.add(sc.next());
        }

        int result = countBit(opereations);
        System.out.println(result);

        sc.close();
    }
}