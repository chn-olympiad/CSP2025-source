#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e6+10;
string a;
int res;
int b[N],idx;

int main()
{
    

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >>a;

   for(int i=0;i<a.size();i++)
   {
       if(a[i]>='0'&&a[i]<='9')
        {
            res++;
            b[idx++]=a[i]-'0';
        }
   }
    
    sort(b,b+res);
    for(int i=res-1;i>=0;i--)
        cout <<b[i];



    return 0;
}