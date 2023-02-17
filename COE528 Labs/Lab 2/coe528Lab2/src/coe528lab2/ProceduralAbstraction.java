/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package coe528lab2;
//import java.util.ArrayList;
import java.util.Scanner;
/**
 *
 * @author Gajanan Vigneswaran
 */
public class ProceduralAbstraction {
    //Requires: None
    //Modifies: None
    //Effects: Returns the smallest positive integer n for which n!
    // (i.e. 1*2*3*...*n) is greater than or equal to x, for positive
    // integer x. Otherwise returns 1.
    public static int reverseFactorial(int x) {
        int fact = 1;
        int i;
        if (x>1){
            for (i=2; fact < x; i++){
                fact *= i;
            }
            return i-1;
        }
        else{
            return 0;
        }
    }
    public static boolean isMatrixNice(int[][] arr) {
        int i, j, n;
        int diagRight = 0, diagLeft = 0, row = 0, row2 = 0;
        boolean ans;
        n = arr.length - 1;
        if (n<1){
          return true;  
        }
        for (i = 0; i <= n; i++){
            if (n+1 != arr[i].length){
                return false;
            }
        }
        n = arr.length - 1;
        
        // gets the sum of the first row, all other sumations will be compared to this one
        for (i = 0; i <= n; i++){
            row += arr[0][i];
        }
        // the sum of the diagonal startiung from the top left
        for (i = 0; i <= n; i++){
            diagRight += arr[i][i];
        }
        // checks if the sum of the diagonal is equal to the referance sum
        if (diagRight != row){
            return false;
        }
        // the sum of the diagonal startiung from the bottom left
        for (i = 0; i <= n; i++){
            diagLeft += arr[n - i][i];
        }
        if (diagLeft != row){
            return false;
        }
        //calculating the sums for each row and checking if it is equal to the reference row 
        for (i = 1; i <= n; i++){
            row2 = 0;
            for (j = 0; j <= n; j++){
                row2 += arr[i][j];
            }
            if (row2 != row){
                return false;
            }
        }
        //calculating the sums for each column and checking if it is equal to the reference row 
        for (i = 0; i <= n; i++){
            row2 = 0;
            for (j = 0; j <= n; j++){
                row2 += arr[j][i];
            }
            if (row2 != row){
                return false;
            }
        }
        //if all of the if statements have not been triggered it passes all the tests and the matrix is Nise and the method will return true
        return true;
    }
    
    
    
    
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        //Getting user input to send appropriate number to get it's reverse factorial
        System.out.println("Enter a number: ");
        int num = sc.nextInt();
        System.out.println("The reverse factorial is: "+reverseFactorial(num)+"\n");
        
        //preset arrays to test the isMatrixNice method 
        int[][] ar1 = {{2, 7, 6},{9, 5, 1},{4, 3, 8}}; //true
        int[][] ar2 = {{1, 1, 1},{1, 1},{1, 1, 1}};//false
        int[][] ar3 = {{1, 1, 1},{1, 1, 1}};//false
        int[][] ar4 = {{1}};//true
        int[][] ar5 = {}; //true
        int[][] ar6 = {{1, 1, 1},{1, 1, 1},{1, 1, 1},{1, 1, 1}};//false
        int[][] ar7 = {{1, 1, 1},{},{1, 1, 1}};//false
        System.out.println(isMatrixNice(ar1));
        System.out.println(isMatrixNice(ar2));
        System.out.println(isMatrixNice(ar3));
        System.out.println(isMatrixNice(ar4));
        System.out.println(isMatrixNice(ar5));
        System.out.println(isMatrixNice(ar6));
        System.out.println(isMatrixNice(ar7));
        
    }    
}
