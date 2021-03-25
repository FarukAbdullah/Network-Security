//Primitive Root calculation for Elgamal Digital Signature

#include <iostream>
#include<math.h>
#include <set>
using namespace std;

void CalculatePrimitiveRoot(int p)
{
     int z=p-1;
    long long r[z][z];
    for(int i=0;i<z;i++)
    {
        for(int j=0;j<z;j++)
        {
            r[i][j]=pow(i+1,j+1);
            r[i][j]%=p;
        }
    }
    set <int> st;
    for(int i=0;i<z;i++)
    {
        for(int k=0;k<z;k++){
            st.insert(r[i][k]);
        }

        if(st.size() == z){
                cout << "Primitive root : "<< i+1<< " ; -> ";
            for(int j=0;j<z;j++)
            {
                cout << r[i][j] << " ";
            }
            cout << '\n';
        }
        st.clear();
    }
}

int main()
{
    int n;
    cout << "Enter a prime number" << endl;
    cin>> n;
    CalculatePrimitiveRoot(n);

    return 0;
}
