#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 5e5+5,M = 21;
int read () {
	int f=1,x=0;char ch=getchar ();
	while (!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
	while (isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
void write (int x) {
	if(x<0) {putchar('-');x=-x;}
	if(x>=10) write(x/10);
	putchar(x%10+48);
}
int n,k,ans,a[N],d[N],mx,sum;
void dfs(int cnt,int now,int s) {
	//cout<<cnt<<' '<<now<<' '<<s<<' '<<mx<<'\n';
	if(s==k) cnt++,s=-1;
	if(now>n) {
		mx=max(mx,cnt);
		return ;
	}
	int x=s^a[now];
	if(s==-1) x=a[now];
	dfs (cnt,now+1,x);
	dfs (cnt,now+1,-1);
} int f=0;
signed main () {
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++) {
		a[i]=read();sum+=a[i];
		if(a[i]>1)f=1;
		d[i]=a[i]^d[i-1];
	} 
	if(k<2&&!f) {
		if(k==1) cout<<sum<<'\n';
		else {
			int cnt=0;
			for(int i=1;i<=n;i++) {
				if(a[i]==1) {
					cnt++;
					if(cnt==2) 
						cnt=0,ans++;
				} else {
					cnt=0,ans++;
				}
			}
		 cout<<ans<<'\n';}
		return 0;
	} else dfs(0,1,-1); 
	cout<<mx<<' ';
	return 0;
}
