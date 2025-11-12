#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500+10];
char s[500+10];

int main(){


	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++)	cin>>s[i];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)	ans++;
	}
	
	long long sum=1,num=0;
	for(int i=m;i<=n-ans;i++){
		for(int j=1;j<=i;j++){
			sum*=j;
			sum%=998244353;
		}
		num+=sum;
		num%=998244353;
		sum=1;
	}
	
	cout<<num%998244353;
	
	return 0;
}
