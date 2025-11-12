#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mk mape_pair
using namespace std;
const int N=1e5+5;
int T,ans,cnt[5],n;
struct Node{int p,v;}nd[N][4];
struct prind{
	int p,vd;
	friend bool operator <(prind x,prind y){return x.vd>y.vd;}
};
priority_queue<prind> q;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		ret=(ret<<3)+(ret<<1)+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
void print(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) print(x/10);
	putchar(x%10+'0');
}
bool cmp(Node x,Node y){return x.v>y.v;}
int chk(){
	for(int i=1;i<=3;i++) if(cnt[i]>n/2) return i;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				nd[i][j].p=j,nd[i][j].v=read();
			sort(nd[i]+1,nd[i]+4,cmp);
			cnt[nd[i][1].p]++;ans+=nd[i][1].v;
			q.push((prind){nd[i][1].p,nd[i][1].v-nd[i][2].v});
		} 
		int v=chk();
		while(v){
			prind tp=q.top();
			while(tp.p!=v){q.pop();tp=q.top();}
			ans-=tp.vd;cnt[v]--;q.pop();
			v=chk();
		}
		print(ans);putchar('\n');
		while(q.size()) q.pop();
		ans=cnt[1]=cnt[2]=cnt[3]=0;
	}
	return 0;
}