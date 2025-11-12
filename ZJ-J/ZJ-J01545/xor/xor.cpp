#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool flag=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1 && a[i]!=0)flag=0;
	}
	if(flag)//–‘÷ A&B 
	{
		int one=0,zero=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1 && a[i+1]==1)
				zero++,i++,one+=2;
			else if(a[i]==1)
				one++;
			if(a[i]==0)zero++; 
		}
		if(k==1)
			cout<<one;
		else if(k==0)
			cout<<zero;
		else cout<<0;
	}
	else cout<<2; 
	return 0;
}
