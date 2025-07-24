import java.util.*;

public class AntonAndPolyhedrons {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int result = 0;

        for(int i = 0; i < n; i++) {
            String curr = sc.next();
            switch (curr) {
                case "Tetrahedron":
                    result += 4;
                    break;
                case "Cube":
                    result += 6;
                    break;
                case "Octahedron":
                    result += 8;
                    break;
                case "Dodecahedron" :
                    result += 12;
                    break;
                case "Icosahedron":
                    result += 20;
                    break;
            }
        }

        System.out.println(result);
        sc.close();
    }
}
