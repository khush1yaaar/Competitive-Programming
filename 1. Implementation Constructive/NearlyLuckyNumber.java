import java.util.*;

public class NearlyLuckyNumber {
    public static boolean isnearlylucky(int n) {
        if(n == 0) {
            return false;
        }
        while(n != 0) {
            int digit = n % 10;
            if(digit != 4 && digit != 7) {
                return false;
            }
            n = n / 10;
        }

        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.nextLine();
        int count = 0;

        for(int i = 0; i < n.length(); i++) {
            int digit = n.charAt(i) - '0';
            if(digit == 4 || digit == 7) {
                count++;
            }
        }

        if(isnearlylucky(count)) {
            System.out.println("YES");
        } 
        else {
            System.out.println("NO");
        }

        sc.close();
    }
}
