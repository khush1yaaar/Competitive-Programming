import java.util.*;

public class ChewbaccaAndNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String number = sc.next();

        StringBuilder result = new StringBuilder();

        for(int i = 0; i < number.length(); i++) {
            int digit = number.charAt(i) - '0';

            if(i == 0 && digit == 9) {
                result.append(digit);
                continue;
            }

            if(digit > 4) {
                result.append(9 - digit);
            }

            else {
                result.append(digit);
            }
        }

        System.out.println(result);
        sc.close();
    }
}