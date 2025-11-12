#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,m,ans,c[505],a[505];
char s[505];
bool fl[505];
bool check(){
	int cnt=0,win=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[a[i]]){
			cnt++;
			continue;
		}
		if(s[i]=='0') cnt++;
		else win++;
		if(win>=m) break;
	}
	return win>=m;
}
void dfs(int l){
	if(l==n+1){
		if(check()) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!fl[i]){
			a[l]=i,fl[i]=1;
			dfs(l+1);
			a[l]=0,fl[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf(" %c",&s[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1);
	printf("%d",ans%P);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/