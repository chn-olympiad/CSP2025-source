#include<bits/stdc++.h>
#define int long long
const int mod=998244353;
using namespace std;
inline int read(){
	int f=0,k=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') k=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) f=f*10+ch-'0';
	return f*k;
}
int a(int x,int y){
	int ans=1,sum=x;
	while(x>=sum-y&&x>0){
		ans=ans*x%mod;
		x--;
	}
	return ans;
}
int m,n,c[501],sum=0;
char ch;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	while(ch=getchar()){
		if(ch=='0'){
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	sort(c+1,c+n+1);
	for(int i=1;sum>=c[i];i++){
		sum++;
	}
	cout<<a(n-sum,m)%mod<<endl;
	return 0;
} 
