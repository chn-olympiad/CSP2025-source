#include<bits/stdc++.h>
#define endl '\n'
#define endline putchar('\n')
#define qwe putchar(' ')
//#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> PII;
typedef long long ll;
inline int read(){
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=1e5+10;
int vis[N],d[4];
int ans;
inline void dfs(int k,int sum,vector<vector<int> > a,int n){
	if(k==n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			if(!vis[i]&&d[j]<n/2){
				cout<<sum<<' ';
				vis[i]=1;
				d[j]++;
				dfs(k+1,sum+a[i][j],a,n);
				vis[i]=0;
				d[j]--;
			}
		}
	}
}
struct Node{
	int b,c;
};
bool cmp(Node x,Node y){
	if(x.b!=y.b) return x.b>y.b;
	return x.c>y.c;
}
bool cmpp(Node x,Node y){
	if(x.c!=y.c) return x.c>y.c;
	return x.b>y.b;
}
int main(){
	freopen("club4.in","r",stdin);
//	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		int n=read();
		ans=0;
		vector<vector<int> > a(n+5,vector<int>(4));
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				a[i][j]=read();
		int s1=0,s2=0;
		for(int i=1;i<=n;i++)
			s1+=a[i][1],s2+=a[i][2];
		if(s1==0&&s2==0){
			vi b;
			for(int i=1;i<=n;i++) b.push_back(a[i][0]);
			sort(b.begin(),b.end(),greater<int>());
			ans=0;
			for(int i=0;i<n/2;i++) ans+=b[i];
			write(ans);endline;
			continue;
		}
		else if(s2==0){
			vector<Node> h(n+5);
			for(int i=1;i<=n;i++) h[i].b=a[i][0],h[i].c=a[i][1];
			sort(h.begin()+1,h.end()-4,cmp);
			ans=0;
			int d1=0,d2=0;
			for(int i=1;i<=n;i++){
				if(h[i].b>h[i].c&&d1<n/2) d1++,ans+=h[i].b;
				else if(h[i].b<=h[i].c&&d2<n/2) d2++,ans+=h[i].c;
			}
			int anss=ans;
			sort(h.begin()+1,h.end()-4,cmpp);
			ans=0,d1=0,d2=0;
			for(int i=1;i<=n;i++){
				if(h[i].b>h[i].c&&d1<n/2) d1++,ans+=h[i].b;
				else if(h[i].b<=h[i].c&&d2<n/2) d2++,ans+=h[i].c;
			}
			write(max(ans,anssa));endline;
			continue;
		}
		memset(vis,0,sizeof vis);
		memset(d,0,sizeof d);
		dfs(0,0,a,n);
		write(ans);endline;
	}
	return 0;
}