#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[510],c[510],r[510],ans;
string s;
int read(){
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	int sum=0;
	while(c>='0'&&c<='9'){
		sum=(sum<<1)+(sum<<3)+(c-'0');
		c=getchar();
	}
	return sum;
}
string readst(){
	char c=getchar();
	while(c<'0'||c>'1') c=getchar();
	string sum="";
	while(c>='0'&&c<='1'){
		sum=sum+c;
		c=getchar();
	}
	return sum;
}
void write(int res){
	if(res==0) return ;
	write(res/10);
	putchar(res%10+'0');
}
bool cmp(int xx,int yy){
	return xx<yy;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	s=readst();
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++) r[i]=r[i-1]+(s[i-1]-'0');
	if(r[n]==n){
		putchar('0');
		return 0;
	}
	if(m==n){
		ans=1;
		sort(c+1,c+n+1,cmp);
		for(int i=n;i>=1;i--){
			int w=upper_bound(c+1,c+n+1,r[i])-c;
			ans=(ans*(i-w+1))%mod;
		}
		if(ans!=0) write(ans);
		else putchar('0');
		return 0;
	}
	if(m==1){
		ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%mod;
		write(ans);
		return 0;
	}
	return 0;
}
