#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s[5005],dp[5005],sum=0;
bool check(int l,int m){
	int sss=a[l];
	for(int i=l+1;i<=m;i++) if(a[l]>sss)sss=a[l];
	if(m>=3&&s[m]-s[l]>sss*2)return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>a[1];
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;j++){
			if(check(j,i))sum++;
		}
	}
}
