import java.util.Scanner;
import java.io.*;
import java.lang.*;
import java.util.Vector;


public class dfs {

    public static int G_MAX = 1000;

    public static void main(String[] argv){
    
    
        Vector<Integer> G = new Vector<Integer> (G_MAX);
        int V,E;
        int s,t;

        Scanner matrixsize = new Scanner(System.in);
        V = matrixsize.nextInt();
        E = matrixsize.nextInt();

        for(int i=0; i < E; i++){
        Scanner stdin = new Scanner(System.in);
        s = stdin.nextInt();
        t = stdin.nextInt();
            G.add(s,t);
        }
        
        System.out.println("Result G " + G.toString());
    }
}

