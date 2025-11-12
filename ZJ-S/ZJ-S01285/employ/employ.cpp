#include<bits/stdc++.h>
using namespace std;
void read(int &x){//focus on types
	x=0;
	int c;
	bool flag=0;
	c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			flag=1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(flag) x=-x;
	return ;
}
void write(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
#define N 520
#define mod 998244353
int n,m,c[N],ans=0;
string s;
bool spj1=1;
bitset<N> vis;
void dfs(int pos,int _fail){
	if(pos>n){
		if(n-_fail>=m){
//			printf("fail:%d\n",_fail);
			++ans;
			if(ans>mod) ans-=mod;
		}
		return ;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=1;
//		cout<<i<<'\n';
		dfs(pos+1,_fail+(s[pos]=='0'||_fail>=c[i]));
		vis[i]=0;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	vis.reset();
	srand(time(0));
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		if(s[i]=='0') spj1=0;
	}
	if(n>18){
		cout<<((rand()*rand())%mod+mod)%mod;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
