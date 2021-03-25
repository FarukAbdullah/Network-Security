using System;
using System.Collections.Generic;
using System.Numerics;
 
namespace PrimitiveRoot
{
    
    class Program
    {
        static void CalculatePrimitiveRoot(int p)
        {
            int z = p - 1;
            BigInteger [,] r = new BigInteger[z, z];
            for(int i=0;i<z;i++)
            {
                for(int j=0;j<z;j++)
                {
                    r[i, j] =(BigInteger) Math.Pow(i + 1, j + 1);
                    r[i,j]%=p;
                }
             }
            HashSet<BigInteger> st = new HashSet<BigInteger>();
            for(int i=0;i<z;i++)
            {   
                for(int k=0;k<z;k++){
                    st.Add(r[i,k]);
                }
 
               if(st.Count == z){
                    Console.Write("Primitive root : " + (i + 1) + " ; -> ");
                    for(int j=0;j<z;j++)
                    {
                        Console.Write(r[i,j] + " ");
                    }
                    Console.WriteLine();
               }
                st.Clear();
            }
        }
        
        static void Main(string[] args)
        {
            int n;
            Console.WriteLine("Enter a prime number");
            n = Convert.ToInt32(Console.ReadLine());
            CalculatePrimitiveRoot(n);
            Console.ReadLine();
        }
    }
 
}
