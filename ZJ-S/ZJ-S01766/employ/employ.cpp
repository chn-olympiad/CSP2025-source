#include<bits/stdc++.h>
using namespace std;
#define ll long long
void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,s[510],c[510],cnt[510],tot,b[510];
ll pw[510],ans;
const ll P=998244353;
void dfs(int x,int now){
	if(now>=m){
		ans=(ans+pw[n-x+1])%P;
		return;
	}
	if(x>tot) return;
	if(now+tot-x+1<m) return;
	for(int i=1;i<=n;i++)
		if(!b[i]){
			b[i]=1;
			dfs(x+1,now+(cnt[x]+x-1-now<c[i]));
			b[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	char ch=getchar();
	while(ch<'0'||ch>'1') ch=getchar();
	for(int i=1;i<=n;i++){
		s[i]=ch-'0',ch=getchar();
		if(s[i]) tot++,cnt[tot+1]=cnt[tot];
		else cnt[tot+1]++;
	}
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*i%P;
	for(int i=1;i<=n;i++) read(c[i]);
	sort(c+1,c+1+n);
	dfs(1,0);
	write(ans);
	putchar('\n');
	return 0;
}
