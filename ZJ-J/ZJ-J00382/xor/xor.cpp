#include<bits/stdc++.h>
//#define int long long

using namespace std;

int n,k,a[1005],ans,maxx,s,d[1005];
bool f[1005][1005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int t=1;t<=n;t++){
		s=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<t;j++){
				s^=a[i+j];
			}
			if(s==k)f[i][i+t-1]=1;
		}
	}
	d[1]=f[1][1];
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			for(int t=i-j+1;t<=i;t++)
			for(int v=t;v<=i;v++)
			d[i]=max(d[i],d[i-j]+f[t][v]);
		}
	}
	cout<<d[n];
	return 0;
}
