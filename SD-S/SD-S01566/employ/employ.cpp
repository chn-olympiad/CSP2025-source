#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
int read() {
	int x=0;
	short f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int mod=998244353,N=510;
int n,m;
string s1;
int ans;
int jie[N],c[N];
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s1;
	jie[1]=1;
	for(int i=2; i<=n; i++) {
		jie[i]=jie[i-1]*i%mod;
	}
	int cnt=0;
	int l1=s1.length();
	for(int i=1;i<=n;i++){
		c[i]=read();	
		if(c[i])
			cnt++;	
	}
	if(m==1) {
		bool flag=0;
		int cnt1=0;
		for(int i=0; i<l1; i++) {
			if(s1[i]=='1')
				cnt1++;
		}
		cout<<cnt<<" "<<cnt1<<endl;
		if((!cnt1)||!cnt){
			cout<<0;			
		}
		else if(cnt==n) {
			cout<<jie[n];
		} else {
			int cur=1;
			for(int i=1; i<=cnt1; i++) {
				cur=cnt;
				for(int j=0; j<i-1; j++) {
					cur=cur*(n-cnt-j)%mod;
				}
				cur=cur*jie[n-i]%mod;
				ans=(ans+cur)%mod;
			}
		cout<<ans;
		}
	}
	else{
		cout<<0;
	}
	return 0;
}

