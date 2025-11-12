#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e5+10;
struct node{
	long long w,num,bm;
}a[N*4];
long long T,n,ans,b[10],c[N],sa[N][4],num1[5],jl[N][4];
bool vis[N];
bool cmp(node ax,node bx){
	if(ax.w>bx.w)return 1;
	return 0;
}
void fun(int h){
	int numm=0;
	for(int i=1;i<=b[h];i++){
		int ww=jl[i][h];
		c[i]=min(abs(sa[ww][h]-sa[ww][h%3+1]),abs(sa[ww][h]-sa[ww][(h+1)%3+1]));
	}
	sort(c+1,c+b[h]+1);
	int j=0;
	while(b[h]>n/2){
		b[h]--;
		ans-=c[++j];
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		long long maxn=0,maxw;
		ans=0;
		memset(jl,0,sizeof(jl));
		memset(num1,0,sizeof(num1));
		b[1]=b[2]=b[3]=0;
		for(int i=1;i<=n;i++){
			cin>>sa[i][1]>>sa[i][2]>>sa[i][3];
			maxn=0;
			for(int j=1;j<=3;j++){
				if(sa[i][j]>maxn)maxn=sa[i][j],maxw=j;
			}
			ans+=maxn;
			jl[++b[maxw]][maxw]=i;
		}
		if(b[1]>(n/2))fun(1);
		if(b[2]>(n/2))fun(2);
		if(b[3]>(n/2))fun(3);
		cout<<ans<<'\n';
	}
	return 0;
}
