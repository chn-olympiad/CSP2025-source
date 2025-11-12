#include<bits/stdc++.h>
//#define int long long
#define FST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define ls(x)(x<<1)
#define rs(x)(x<<1|1)
#define mid(l,r)((l+r)>>1)
#define fclose buyaojiafclose
using namespace std;
int n,m;
char s[20];
int c[12];
int p[12];
bool vis[12];
int ans=0;
void pd(){
	int zcnt=0,num=0;
	for(int i=1;i<=n;i++){
		if(zcnt>=c[p[i]]){
			zcnt++;continue;
		}
		if(s[i]=='1')num++;
		else zcnt++;
	}
	if(num>=m)ans++;
}
void d(int x){
	if(x==n+1){
		pd();
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		p[x]=i;
		d(x+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	d(1);
	cout<<ans<<endl;
	return 0;
}

