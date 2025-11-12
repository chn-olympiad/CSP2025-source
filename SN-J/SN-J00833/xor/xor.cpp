//SN-J00833 白敬轩 西安高新一中沣东中学 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x;
	cin >> n >> k;
	int sum1=0,sum0=0;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		if(x==1) sum1++;
		if(x==0)sum0++;
	}
	if(k==1)cout << sum1;
	if(k==0)cout<<sum0;
} 
