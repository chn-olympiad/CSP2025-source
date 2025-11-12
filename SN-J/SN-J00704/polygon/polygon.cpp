#include<bits/stdc++.h>
using namespace std;
const int inf=998244353,N=5003;
int n,a[N],sum,cnt,maxn;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=3;i>=n;i++){
		for(int j=1;j<=i;j++){
			cnt+=a[j];
			maxn=max(maxn,a[j]);
		}
		if(cnt>maxn){
			sum++;
			cnt=0;
			maxn=0;
		}
	}
	cout<<sum%inf;
}
