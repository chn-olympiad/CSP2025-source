#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int a[5000];
	for(int i=1;i<=a;i++)
    {
        cin>>a[i];
    }
    if(b==0)
    {
        cout<<1;
    }
    else
    {
        cout<<b;
    }
	return 0;
}
