import java.util.*;

public class TheNewYearMeetingFriends {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x1 = sc.nextInt();
        int x2 = sc.nextInt();
        int x3 = sc.nextInt();

        // Sort the three points to find the median
        int[] points = {x1, x2, x3};
        Arrays.sort(points);
        int median = points[1]; // The middle one after sorting

        int result = Math.abs(median - x1) + Math.abs(median - x2) + Math.abs(median - x3);
        System.out.println(result);

        sc.close();
    }
}