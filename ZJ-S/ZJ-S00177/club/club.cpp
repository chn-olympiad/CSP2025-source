#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 500005
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int sum[4];
int v[maxn][4];
struct node{
	int x,dx,t;
	bool operator<(const node a)const{
		return dx<a.dx;
	}
}A[maxn];
int n;
int a,b,c;
int cnt=0;
priority_queue<node>q;
void solve(){
	n=read();
	cnt=0;
	for(int i=1;i<=n;i++){
		a=read(); b=read(); c=read(); v[i][1]=a; v[i][2]=b; v[i][3]=c;
		A[i].x=i; A[i].dx=2*max(a,max(b,c))+min(a,min(b,c))-a-b-c;
		if(max(a,max(b,c))==v[i][1])A[i].t=1;
		else if(max(a,max(b,c))==v[i][2])A[i].t=2;
		else A[i].t=3;
		q.push(A[i]);
	}
	for(int i=1;i<=3;i++)sum[i]=0;
	int ans=0;
	while(!q.empty()){
		node R=q.top(); q.pop();	
		if(sum[R.t]==n/2){
			R.dx=v[R.x][1]+v[R.x][2]+v[R.x][3]-max(v[R.x][1],max(v[R.x][2],v[R.x][3]))-2*min(v[R.x][1],min(v[R.x][2],v[R.x][3]));
			int g=v[R.x][1]+v[R.x][2]+v[R.x][3]-max(v[R.x][1],max(v[R.x][2],v[R.x][3]))-min(v[R.x][1],min(v[R.x][2],v[R.x][3]));
			if(g==v[R.x][1]&&R.t!=1)R.t=1;
			else if(g==v[R.x][2]&&R.t!=2)R.t=2;
			else R.t=3;
			q.push(R);
		}		
		else{
			sum[R.t]++;
			ans+=v[R.x][R.t];
		}
	}
	write(ans); cout<<'\n';
}
signed main(){	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; T=read(); while(T--)solve();	
	return 0;
}