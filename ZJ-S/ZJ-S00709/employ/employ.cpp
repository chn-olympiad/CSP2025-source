#include<bits/stdc++.h>
using namespace std;
long long a[505],ans=1,op=1,mod=998244353,x;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,t,cnt=0,sum=0;
	string s;
	cin>>n>>m>>s;
	if(m==n){
		for(int i=0;s[i];i++){
			if(s[i]=='0'){
				cout<<"0\n";
				return 0;
			}
		}
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(a[i]<i){
				cout<<"0\n";
				return 0;
			}
		}
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=0;s[i];i++){
		sum+=(!(s[i]-'0'));
		while(a[op]<=sum)op++;
		if(op>n)break;
		ans=ans*(n-op+1)%mod;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
