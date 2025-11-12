#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,Mod=998244353;
int n,m;
long long t[N];
long long ans;
string s;
int a[N];
int b[N];
bool c[N];
int tmp;
void inti() {
	t[0]=1;
	for(int i=1; i<=n; i++) {
		(t[i]=t[i-1]*i)%Mod;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	inti();
	cin>>s;
	for(int i=0; i<=s.size(); i++) {
		c[i]=s[i]-'0';
		b[i]=b[i-1]+c[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==0) tmp++;
	}
	if(n-tmp<m) {
		cout<<0<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	if(b[n-1]==n) {
		cout<<t[n]<<endl;
		return 0;
	}
	tmp=0;
	int k=0;
	for(k=1; k; k++) {
		if(a[k]) break;
	}
	for(int i=1; i<=n; i++) {
		if(c[i]==1) {
			tmp++;
			long long sum=0;
			for(int j=k; j; j++) {
				if(a[j]>i-tmp) break;
				sum++;
			}
			if(ans) ans=(ans*(sum-tmp))%Mod;
			else ans=sum-tmp+1;
		}
	}
	ans=(ans*t[n-tmp])%Mod;
	cout<<ans<<endl;
	return 0;
}

