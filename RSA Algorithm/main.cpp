//RSA Algorithm//

#include<iostream>
#include<math.h>

using namespace std;

int gcd(int a, int b) {
   int temp;
   while(1) {
      temp= a%b;
      if(temp==0)
      return b;
      a = b;
      b= temp;
   }
}

void decrypt( string de, double m, double n)
{
    if(de == "y")
    {
        double me=fmod(m,n);
        cout<<"\nDecrypted message : "<<me<<endl;
    }
    else if(de == "n")
   {
       cout << " ";
   }
   else
   {
       cout<< "You enter wrong Input  !!!!";
   }

}

int main()
 {
   double p,q,t;
   cout<< "Enter any two prime numbers : ";
   cin>> p>>q;
   double n=p*q;
   double phi= (p-1)*(q-1);

   double e=3;
   while(e<phi) {
      t = gcd(e,phi);
      if(t==1)
         break;
      else
         e++;
   }


   double d1=1/e;
   double d=fmod(d1,phi);
   double me;
   cout << "\nEnter Messages (number) : ";
   cin >> me;
   double c = pow(me,e);
   double m = pow(c,d);
   c=fmod(c,n);
   cout <<"\nEncrypted message : "<<c<<endl;
   string de;
   cout << "\nDo you want to Decrypt the message ? [y/n] \n";
   cin>> de;
   decrypt(de,m,n);

   cout << endl;
   return 0;
}
