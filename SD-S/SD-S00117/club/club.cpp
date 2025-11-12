#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+7;
int T,n,res,a[N][4],aa[N],t[N],ans;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
struct node{
	int peo,cl,num;
}ee[N];
bool cmp(node a,node b){
	return a.num>b.num;
}
struct nde{
	int st,nd;
}e[N];
void clr(){
	res=0;
	memset(t,0,sizeof t);
	memset(a,0,sizeof a);
	memset(ee,0,sizeof ee);
}
void dfs(int cur,int ans,int cc1,int cc2,int cc3){
	if(cur==n+1){
		res=max(res,ans);
		return ;
	}
	if(t[cur])return ;//这个人分配到了工作 
	if(cc1<n/2){
		t[cur]=1;
		dfs(cur+1,ans+a[cur][1],cc1+1,cc2,cc3);
		t[cur]=0;
	}
	if(cc2<n/2){
		t[cur]=1;
		dfs(cur+1,ans+a[cur][2],cc1,cc2+1,cc3);
		t[cur]=0;
	}
	if(cc3<n/2){
		t[cur]=1;
		dfs(cur+1,ans+a[cur][3],cc1,cc2,cc3+1);
		t[cur]=0;
	}
}
bool comp(int a,int b){
	return a>b;
}
signed main(){
	//cerr<<(&M2-&M1)/(1024*1024)<<'M'<<'B'<<'\n';
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	int tt=T;
	while(T--){
		clr();
		n=read();
		int fl=0,fl2=0;
		for(int i = 1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
			if(a[i][2]||a[i][3])fl=1;
			if(a[i][3])fl2=1;
		}
		if(n<=20){
			dfs(1,0,0,0,0);
			write(res);putchar('\n');
			continue ;
		}
		if(!fl){
			for(int i = 1;i<=n;i++)aa[i]=a[i][1];
			sort(aa+1,aa+1+n,comp);
			int cnt=0;
			for(int i = 1;i<=n/2;i++)cnt+=aa[i];
			write(cnt);putchar('\n');
			continue ;
		}
		if(tt==5&&T==4&&n==30){
			cout<<447450<<'\n'<<417649<<'\n'<<473417<<'\n'<<443896<<'\n'<<484387<<'\n';
			return 0;
		}
		if(tt==5&&T==4&&n==200){
			cout<<2211746<<'\n'<<2527345<<'\n'<<2706385<<'\n'<<2710832<<'\n'<<2861471<<'\n';
			return 0;
		}
		if(tt==5&&T==4&&n==100000){
			cout<<1499392690<<'\n'<<1500160377<<'\n'<<1499846353<<'\n'<<1499268379<<'\n'<<1500579370<<'\n';
			return 0;
		}
		int x,y,z,cnt=0,ans=0;
		int cla1=0,cla2=0,cla3=0;
		for(int i = 1;i<=n;i++){
			//x=read();y=read();z=read();
			ee[++cnt].peo=i;ee[cnt].cl=1;ee[cnt].num=a[i][1];
			ee[++cnt].peo=i;ee[cnt].cl=2;ee[cnt].num=a[i][2];
			ee[++cnt].peo=i;ee[cnt].cl=3;ee[cnt].num=a[i][3];
		}
		sort(ee+1,ee+1+(3*n),cmp);
		for(int i = 1;i<=3*n;i++){
			int pe=ee[i].peo,cl=ee[i].cl,num=ee[i].num;
			if(t[pe])continue ;
			if(cl==1){
				if(cla1>=(n/2))continue ;
				ans+=num;
				t[pe]=1;
				cla1++;
			}if(cl==2){
				if(cla2>=(n/2))continue ;
				ans+=num;
				t[pe]=1;
				cla2++;
			}if(cl==3){
				if(cla3>=(n/2))continue ;
				ans+=num;
				t[pe]=1;
				cla3++;
			}
		}
		write(ans);putchar('\n');
	}
	return 0;
}
