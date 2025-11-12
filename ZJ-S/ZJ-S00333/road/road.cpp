#include<bits/stdc++.h>
using namespace std;
#define int long long
#define p_ putchar(' ')
#define pn putchar('\n')
#define mk(x,y) make_pair(x,y)
#define fr first
#define se second
void write(int x){
	if(x<0){
		putchar('-');
		write(-x);
		return ;
	}
	if(x>=10){
		write(x/10);
	}
	putchar(x%10+'0');
}
int read(){
	int w=1,s=0;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-'){
		w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}
const int N=1e4+15,M=1e6+5;
int n,m,k,UU[M],VV[M],WW[M],Ans,fa[N],a[15][N],c[15],use[15];
priority_queue<pair<int,pair<int,int> > >q;
int gf(int x){
	if(x!=fa[x]){
		return fa[x]=gf(fa[x]);
	}
	return fa[x];
}
void check(){
	for(int i=1;i<=m;i++){
		q.push(mk(-WW[i],mk(UU[i],VV[i])));
	}
	int ans=0,num=n;
	for(int i=1;i<=k;i++){
		if(use[i]){
			ans+=c[i];num++;
			for(int j=1;j<=n;j++){
				q.push(mk(-a[i][j],mk(num,j)));
			}
		}
	}
	for(int i=1;i<=num;i++){
		fa[i]=i;
	}
	int sum=num-1;
	while(sum){
		if(gf(q.top().se.fr)!=gf(q.top().se.se)){
//			write(q.top().fr);p_;write(q.top().se.fr);p_;write(q.top().se.se);pn;
			ans-=q.top().fr;sum--;
			fa[gf(q.top().se.fr)]=gf(q.top().se.se);
		}
		q.pop();
	}
	Ans=min(Ans,ans);
}
void dfs(int t){
	if (t>=k+1){
		check();
		return ;
	}
	use[t]=0;
	dfs(t+1);
	use[t]=1;
	dfs(t+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	Ans=1e9+7;
	for(int i=1;i<=m;i++){
		UU[i]=read(),VV[i]=read(),WW[i]=read();
	}
	bool p=1;
	for(int i=1;i<=k;i++){
		c[i]=read();if(c[i]!=0)p=0;
		for(int j=1;j<=n;j++){
			a[i][j]=read();if(a[i][j]!=0)p=0;
		}
	}
	if(p){
		for(int i=1;i<=k;i++){
			use[i]=1;
		}
		check();
	}
	else{
		dfs(1);
	}
//	use[1]=1;
//	check();
	write(Ans);
}
/*
The last dance?
What can I say?
math,graph,string
I can't solve any one.
OI has accompanied me from 2019 to 2025.
It's the time to be awaw from OI.
OI changed me.OI shaped me.
I can't imagine the life that I had't encountered OI.
Why I choose to join in the OI competition?
I'm not talented at all.
I'm an ordinary student.
It is surprised that I almost can't adapt the long time of CSP,4h,during 1 years AFO.
Is the traditional way to study OI is efficient?
The answer might not be straightforward.
Obviously ,the outlook of OI is shriving,but not of me.
The problem's name is road,I can't help remembering my own road.
It's isn't the shortest road,but it is truly a fantastic road.
That's all.
by zjyqwq,from Zhuji Senior High.
*/
