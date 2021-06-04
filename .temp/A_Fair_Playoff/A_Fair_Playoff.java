import java.util.Scanner;

public class A_Fair_Playoff {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int t = scn.nextInt();
        while (t-- > 0) {
            int s1 = scn.nextInt();
            int s2 = scn.nextInt();
            int m1 = Math.max(s1, s2);
            // System.out.println(m1);
            int s3 = scn.nextInt();
            int s4 = scn.nextInt();
            int m2 = Math.max(s3, s4);
            // System.out.println(m2);
            if ((m1 > s3 || m1 > s4) && (m2 > s1 || m2 > s2)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        scn.close();
    }
}