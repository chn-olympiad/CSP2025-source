#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f; 
} 

const int N=19;

int n,m,c[N],dp[N][1<<N],p[N],book[N],ans;

string s;

void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(i-1-cnt>=c[p[i]])continue;
			if(s[i-1]=='1'){
				cnt++;
			}
		}
		if(cnt>=m){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(book[i])continue;
		book[i]=1;
		p[i]=x;
		dfs(x+1);
		book[i]=0;
	}
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	n=read();m=read();
	
	cin>>s;
	
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	
	dfs(1);
	
	cout<<ans%998224353<<endl;
	
	return 0;
}
