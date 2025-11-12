#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int rd(){int res=0,f=1;char x=getchar();
	while(x<'0'||'9'<x){if(x=='-')f*=-1;x=getchar();}
	while('0'<=x&&x<='9')res=res*10+x-'0',x=getchar();
return res*f;}
void wt(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)wt(x/10);
	putchar(x%10+'0');
return;}
const int N=12,MOD=998244353;
int n,m,book[N],c[N];
char a[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++)book[i]=i,c[i]=rd();
	do{int cntz=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='1'&&cntz<c[book[i]])++cnt;
			else cntz++;
		}(ans+=(cnt>=m))%=MOD;
	}while(next_permutation(book+1,book+1+n));
	wt(ans);
	return 0;
}

