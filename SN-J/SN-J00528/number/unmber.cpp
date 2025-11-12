#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
    freopen("unmber.in","r",stdin);
    freopen("unmber.out","w",stdout);
    string s;
    cin>>s;
	string a;
    long long len = s.size();
    int b = 0;
    for(long long i = 0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
			b++;
            a[b] = s[i];
            
        }
    }
	
    for(long long i = 1;i<b;i++)
    {
        for(long long j = i+1;j<=b;j++)
        {
            if(a[j]>a[i])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    for(long long i = 1;i<=b;i++)
    {
        cout<<a[i];
    }
    return 0;
}

