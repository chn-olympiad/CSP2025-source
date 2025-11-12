#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

const int N =200010;

int n,q;
string s1[N],s2[N];

int main()
{

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin >> n>>q;
    for(int i=0;i<n;i++)
    {
        cin >> s1[i] >>s2[i];
    }
    while(q--)
    {
        string a,b;
        cin >>a>>b;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(a==s1[i])
                flag=1;
        }
        if(flag ==0)
            cout << 0<<endl;
    }
    


    return 0;
    
}