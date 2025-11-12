#include<bits/stdc++.h>
using namespace std;
long long m=0,maxm=0;
long long a[10000],n,b[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+3;j>i&&j!=n;j++){
				for(int l=i;l<=j;l++){
					m+=a[l];
					maxm=max(a[l],maxm);
				}
				b[i]=m;
				for(int l=i;l<j;l++){
					b[i]-=a[l];
				}
				if(m>maxm*2)cnt++;
		}
	}
	cout<<cnt%998244353;
	return 0;
}
