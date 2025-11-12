// bu gua fen de qing kuang xia
//yun qi cha 5pts
//yun qi hao ?pts
//yun qi:10%
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int TT=998244353;
const int maxn=505;
int n,m,k,c[maxn],fac[maxn];//,cur,pos[maxn];
//int nxt[maxn],pre[maxn];
bool a[maxn];
//bool check(){
//	for(int i=1;i<=n;i++)if(!a[i])return 0;
//	return 1;
//}
int Fac(int x){return x==0?(fac[0]=1):(fac[x]=Fac(x-1)*x%TT);}
//int DFS(int i,int j,int need,int tiao,int lstp,int cur){
//	cerr<<i<<' '<<j<<' '<<need<<' '<<tiao<<' '<<lstp<<' '<<cur<<endl;
//	if(need==0)return fac[cur];
//	if(i>n||j>k)return 0;
//	if(n-i+1<need||k-j+1<need)return 0;
//	int ret=DFS(i+1,j,need,tiao,lstp,cur);
//	int new_tiao=tiao+pos[i]-lstp-1,poss=j-1,new_cur=cur;
//	while(j>=1&&j<=k&&new_tiao>=c[j])new_cur--,cerr<<j<<' ',j=nxt[j];pre[j]=poss,nxt[poss]=j;cerr<<endl;
//	cerr<<new_tiao<<' '<<cur<<endl;
//	for(int l=j;l<=k;l++){
//		int lst=pre[l];
//		nxt[lst]=nxt[l];
//		pre[nxt[l]]=lst;
//		if(l>j)ret=(ret+DFS(i+1,j,need-1,new_tiao,pos[i],new_cur-1))%TT;
//		else ret=(ret+DFS(i+1,j+1,need-1,new_tiao,pos[i],new_cur-1))%TT;
//		nxt[lst]=l;
//		pre[nxt[l]]=l;
//	}
//	return ret;
//}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;int tot=0;
	for(int i=1;i<=n;i++){
		scanf("%1d",a+i);
//		if(a[i])pos[++tot]=i;
	}
	for(int i=1;i<=n;i++)scanf("%lld",c+i);
	sort(c+1,c+n+1,greater<int>());
	for(int i=1;i<=n+1;i++)if(!c[i]){
		k=i-1;
		break;
	}
	n=tot;
	reverse(c+1,c+k+1);
//	for(int i=1;i<=k;i++)nxt[k]=k+1,pre[k]=k-1;nxt[0]=1,pre[k+1]=k;
//	cerr<<n<<' '<<m<<' '<<k<<endl;
	if(n<m||k<m){
		cout<<0;
		return 0;
	}
//	cout<<DFS(1,1,m,0,0,k);
	if(n==m)cout<<Fac(n);
	else cout<<Fac(k);
	return 0;
}

