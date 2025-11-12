#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int t,n,ans,l;
int arr[5][100010];
void dfs(int p1,int p2,int p3,int id,int sum){
	if(id>n){
		ans=max(ans,sum);
		return;
	}
	if(p1+1<=l) dfs(p1+1,p2,p3,id+1,sum+arr[1][id]);
	if(p2+1<=l) dfs(p1,p2+1,p3,id+1,sum+arr[2][id]);
	if(p3+1<=l) dfs(p1,p2,p3+1,id+1,sum+arr[3][id]);
}
bool cmp(int a,int b){
	return a>b;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--) {
		bool flag=1;
		n=read();
		l=n/2;
		ans=-1e9;
		for(int i=1; i<=n; i++) {
			arr[1][i]=read();
			arr[2][i]=read();
			arr[3][i]=read();
			if(arr[2][i]!=0||arr[3][i]!=0) flag=0;
		}
		if(flag){
			ans=0;
			sort(arr[1]+1,arr[1]+n+1,cmp);
			for(int i=1;i<=l;i++) ans+=arr[1][i];
		}else{
			dfs(0,0,0,1,0);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//csp-2025 rp++!
//SD-S00666
//Èü²©·ð×æ±£ÓÓ
