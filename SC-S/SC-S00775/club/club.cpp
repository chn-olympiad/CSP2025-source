#include<bits/stdc++.h>
using namespace std;
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}
const int MAXN=1e5+10;
const int mod=998244353;

int T,n,cnt,val[MAXN][3],c[MAXN];
bool vis[MAXN];
struct node{
	int val,id,to;
}p[MAXN*3];

bool cmp(node n1,node n2){
	return n1.val>n2.val;
}

bool cmp2(int n1,int n2){
	return val[n1][0]-val[n1][1]<val[n2][0]-val[n2][1];
}

void solve(){
	vector<int> t[3];
	n=read();
	cnt=0;
	for(int i=1;i<=n;i++){
		vis[i]=false;
		c[i]=0;
		for(int j=0;j<3;j++){
			p[++cnt].val=read();
			p[cnt].id=i;
			p[cnt].to=j;
		}
	}
	sort(p+1,p+cnt+1,cmp);
	int ans=0;
	for(int i=1;i<=cnt;i++){
		node now=p[i];
		val[now.id][c[now.id]++]=now.val;
		if(!vis[now.id]){
			t[now.to].push_back(now.id);
			ans+=now.val;
			vis[now.id]=true;
		}
	}
	sort(t[0].begin(),t[0].end(),cmp2);
	sort(t[1].begin(),t[1].end(),cmp2);
	sort(t[2].begin(),t[2].end(),cmp2);
	for(int i=0;i<3;i++){
		if(t[i].size()>n/2){
			for(int j=1;j<=t[i].size()-n/2;j++){
				ans-=val[t[i][j-1]][0]-val[t[i][j-1]][1];
			}
		}
	}
	cout<<ans<<'\n';
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club5.in","r",stdin);
//	freopen("club5.out","w",stdout);
	T=read();
	while(T--) solve(); 
	return 0;
}
