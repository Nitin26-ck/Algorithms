import java.util.*;
public class Horspool  {
  
   public static int SIZE=500;    
   public static int table[]=new int[SIZE];
  
public void shifttable(String pattern) {
 
 int i,j,m;
 char p[] = pattern.toCharArray();
 m=pattern.length();
 
 for (i=0;i<SIZE;i++)
    table[i]=m;
 for (j=0;j<m;j++)
    table[p[j]]=m-1-j;
}
public int horspool(String source,String pattern)
  {
      int i,k,pos,m;
      char s[] = source.toCharArray();
      char p[] = pattern.toCharArray();
      m=pattern.length();
     
      for(i=m-1;i<source.length();)
        {
           k=0;
            while((k<m) && (p[m-1-k] == s[i-k]))
              k++;
           if(k==m) 
     {   pos=i-m+2;
               return pos;
     } 
           else
               i+=table[s[i]];
        }
        return -1;
  } 
     public static void main(String []args){
        int pos; 
  String source=args[0];
        String pattern = args[1];
  
        Horspool  h = new Horspool ();       
        h.shifttable(pattern);
        pos = h.horspool(source,pattern);

        if(pos == -1)
            System.out.println("PATTERN NOT FOUND");
        else
            System.out.println("PATTERN FOUND FROM POSITION: \t"+pos+"\n");
     }
}