import java.util.*;

public class FoxAndSnake {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        char[][] grid = new char[n][m];
        boolean switchRow = false;
        boolean left = true;

        for(int i = 0; i < n; i++) {
            if(switchRow) {
                char[] row = grid[i];
                if(left) {
                    Arrays.fill(row, '.');
                    row[m - 1] = '#';
                } else {
                    Arrays.fill(row, '.');
                    row[0] = '#';
                }
                left = !left;
                switchRow = false;
            }
            else {
                char[] row = grid[i];
                Arrays.fill(row, '#');
                switchRow = true;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                System.out.print(grid[i][j]);
            }
            System.out.println();
        }
        sc.close();
    }
}
