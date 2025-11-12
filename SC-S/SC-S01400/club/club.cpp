#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return s*f;
}
const int N=1e5+5;
int T;
int n,fl,ans,f1,f2;
struct node{
	int x,y,z;
}a[N];
int Max(int u,int v,int w){return max(u,max(v,w));}
bool cmp(node A,node B){return A.x>B.x;}
bool cmp2(node A,node B){return Max(A.x,A.y,A.z)<Max(B.x,B.y,B.z);}
int s1[N],sll;
int b[205][205][205];
void dfs(int x,int num1,int num2,int num3,int sum){
	if(sum+s1[n]-s1[x-1]<=ans) return ;
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(sll&&b[num1][num2][num3]>sum) return ;
	b[num1][num2][num3]=sum;
	if(num1<fl) dfs(x+1,num1+1,num2,num3,sum+a[x].x); 
	if(num2<fl) dfs(x+1,num1,num2+1,num3,sum+a[x].y); 
	if(num3<fl&&f2) dfs(x+1,num1,num2,num3+1,sum+a[x].z); 
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();fl=n/2;
		if(n<=300) sll=1;
		ans=0;
		memset(b,-1,sizeof b);
		for(int i=1;i<=n;i++){
			a[i].x=read(),a[i].y=read(),a[i].z=read();
			if(a[i].z!=0) f1=f2=1;
			if(a[i].y!=0) f1=1;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++)
			s1[i]=s1[i-1]+Max(a[i].x,a[i].y,a[i].z);
		if(n<=30||!f2){
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
		}else if(!f1){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=fl;i++) ans+=a[i].x;
			cout<<ans<<'\n';
		}
	}
	return 0;
}