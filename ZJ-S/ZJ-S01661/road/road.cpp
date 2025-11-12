#include<bits/stdc++.h>
using namespace std;
const int N=2e4+15,M=1e6+15;
int f[N];
int n,m,k;
long long ans=0x3f3f3f3f3f3f3f3f;
long long res[15];
struct node{
	int u,v;
	long long w;
}now[2*M],t[1<<10][2*N],village[15][N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int get(int x){
	if(f[x]!=x) return f[x]=get(f[x]);
	return x;
}
void nowsort(int op,int len,int len114){
	int temp=op^(1<<(len-1));
	int len1=1,len2=1;
	for(int i=1;i<=2*n+len114-1;i++){
		if(len1<=(n+len114-1)&&t[temp][len1].w<=village[len][len2].w)
			now[i]=t[temp][len1++];
		else 
			now[i]=village[len][len2++];
	}
	return ;
}
void tree(int op,int len,long long basic,int len1){
	long long cnt=0,sum=basic;
	for(int i=1;i<=n+15;i++) f[i]=i;
	for(int i=1;cnt<n+len1-1;i++){
		int u=get(now[i].u),v=get(now[i].v);
		if(u!=v){
			cnt++;
			f[u]=v;
			t[op][cnt]=node{now[i].u,now[i].v,now[i].w};
			sum+=now[i].w;
		}
	}
	ans=min(ans,sum);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>now[i].u>>now[i].v>>now[i].w;
	sort(now+1,now+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>res[i];
		for(int j=1;j<=n;j++){
			cin>>village[i][j].w;
			village[i][j].u=n+i; village[i][j].v=j;
		}
		sort(village[i]+1,village[i]+n+1,cmp);
	}
	for(int i=0;i<(1<<k);i++){
		int op=i,len=0,len1=0;
		long long sum=0;
		if(i!=0){
			while(op){
				len++;
				if(op&1) len1++,sum+=res[len];
				op>>=1;
			}
			nowsort(i,len,len1);
		}
		tree(i,len,sum,len1);
	}
	cout<<ans;
	return 0;
}
