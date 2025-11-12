#include<bits/stdc++.h>
using namespace std;
long long n,q;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
	srand(100000000);
    for(int i=1;i<=q;i++)
	{ 
		long long k=rand();
		cout<<k%10<<endl;
	}
	return 0;
}
