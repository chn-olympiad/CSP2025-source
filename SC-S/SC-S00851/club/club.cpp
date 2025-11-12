#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	}
	return s*w;
}
void write(int x){
	if(x<0){
		putchar('-');
		write(-x);
		return ;
	}
	if(x<=9){
		putchar('0'+x);
		return ;
	}
	write(x/10);
	putchar('0'+x%10);
	return ;
}
const int N=1e5+5;
const int M=1e3+5;
const int mod=998244353;
const int inf=1e18+7;
int a[N][4],ji[N],cnt[4];
struct node{
	int id,w;
};
bool operator <(const node &x,const node &y){
	return x.w>y.w;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	int n=read();
//	write(n);
//	puts("");
//	return 0;
	int T=read();
	while(T--){
		priority_queue <node> q;
		int n=read();
		memset(cnt,0,sizeof(cnt));
		int ans=0;
		for(int i=1;i<=n;i++){
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			int maxn=-inf,maxd=0,cimaxn=-inf,cimaxd=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]>maxn){
					cimaxn=maxn,cimaxd=maxd;
					maxn=a[i][j],maxd=j;
				}
				else if(a[i][j]>=cimaxn){
					cimaxn=a[i][j];
					cimaxd=j;
				}
			}
			cnt[maxd]++;
			ans+=maxn;
			ji[i]=maxd;
			q.push({i,maxn-cimaxn});
//			cout<<"maxn "<<maxn<<" "<<maxd<<" "<<cimaxn<<" "<<cimaxd<<endl;
		}
		int jl=0;
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2)jl=i;
		}
//		cout<<"jl "<<jl<<endl;
		while(cnt[jl]>n/2){
			node t=q.top();
//			cout<<"t "<<t.id<<" "<<t.w<<endl;
			q.pop();
			if(ji[t.id]!=jl)continue;
			ans-=t.w;
			cnt[jl]--;
		}
		write(ans);
		puts("");
	}
	return 0;
} 