
public class ASS2 { 











    
    public static void towerOfHanoi(int n, String src, String helper, String dest) { 
        if(n == 1) { 
            System.out.println("transfer disk " + n + " from " + src + " to " + dest); 
            return; 
        } 
        
        // 1. Transfer top n-1 disks from src to helper using dest as helper
        towerOfHanoi(n-1, src, dest, helper); 
        
        // 2. Transfer nth disk from src to dest
        System.out.println("transfer disk " + n + " from " + src + " to " + dest); 
        
        // 3. Transfer n-1 disks from helper to dest using src as helper
        towerOfHanoi(n-1, helper, src, dest); 
    } 
    
    public static void main(String args[]) { 
        int n = 2; 
        towerOfHanoi(n, "A", "B", "C"); 
    } 
}
