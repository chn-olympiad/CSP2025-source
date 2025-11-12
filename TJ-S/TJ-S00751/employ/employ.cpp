#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int a[505],c[1005],n,m,ans;
bool b[1005],lu[1005];
void dfs(int step,int luqu) {
	if(step>n) {
		if(luqu>=m) {
			ans=(ans+1)%998244353;
		}
	}
	for(int i=1;i<=n;i++){
		if(!lu[i]){
			lu[i]=1;
			if(a[i]>c[step]){
				dfs(step+1,luqu+1);
			}
			else{
				dfs(step+1,luqu);
			}
			lu[i]=0;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int cnt=0;
	cin>>n>>m;
	string s;
	cin>>s;
	bool a1=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		b[i]=s[i-1]-'0';
		if(b[i])cnt++;
	}
	for(int i=1; i<=n; i++) {
		if(!b[i])continue;
		int cnt=0;
		for(int j=1; j<i; j++) {
			if(!b[j]) {
				cnt++;
			}
		}
		c[i]=cnt;
	}

	if(cnt<m) {
		cout<<0;
		return 0;
	}
	if(cnt==n) {
		long long sum=1;
		for(int i=1; i<=n; i++) {
			sum=(sum*i)%998244353;
		}
		cout<<sum<<endl;
		return 0;
	}
	if(m==1) {
		long long ans=0,sum=0,cntup=0;
		for(int i=1; i<=n; i++) {
			if(!b[i])continue;
			for(int j=1; j<=n; j++) {
				if(a[j]>c[i]) {
					cntup++;
				}
			}
			for(int j=1; i<n; i++) {
				sum=sum*i%998244353;
			}
			sum=sum*cntup%998244353;
			ans=(ans+sum)%998244353;
			sum=0;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
