#include <bits/stdc++.h>
using namespace std;
int n,m;
int main() {
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	long long q=1,w=1;
	for(int i=1;i<=n;i++)
	{
		q*=i;
	}
	for(int i=1;i<=m;i++)
	{
		w*=i;
	}
	if(m==n) cout<<q;
	else if(m==1) 
	{
		int ans=1;
		for(int i=0;i<n;i++)ans*=2;
		cout<<ans-1;
	}
	else{cout<<q/w;
	}
	return 0;
}

