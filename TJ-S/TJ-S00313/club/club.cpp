#include<bits/stdc++.h>
using namespace std;
long long a[10000000],n,m,b[10000000],c[10000000],fa,fb,snn,la,lb,lc;
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
			if(b[j]!=0||c[j]!=0) fa++;
		}
		sort(a+1,a+m+1);
		for(int j=1;j<=m/2;j++) snn+=a[m-j+1];
		cout<<snn;
	}
	return 0;
}
