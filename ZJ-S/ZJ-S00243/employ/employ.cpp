#include<bits/stdc++.h>//CCF RP--
using namespace std;//CCF RP--
inline int read() {//CCF RP--
	int x=0,f=1;//CCF RP--
	char c=getchar();//CCF RP--
	while(c<'0'||c>'9') {//CCF RP--
		if(c=='-')f=-1;//CCF RP--
		c=getchar();//CCF RP--
	}//CCF RP--
	while(c>='0'&&c<='9') {//CCF RP--
		x=x*10+c-'0';//CCF RP--
		c=getchar();//CCF RP--
	}//CCF RP--
	return x*f;//CCF RP--
}//CCF RP--
int n,m,ans;//CCF RP--
bool a[505];//CCF RP--
int c[505],vis[505];//CCF RP--
void dfs(int idx,int sum,int sum2) {//CCF RP--
	if(idx==n+1) {//CCF RP--
		if(sum>=m)ans++;//CCF RP--
		return;//CCF RP--
	}//CCF RP--
	for(int i=1; i<=n; i++) {//CCF RP--
		if(!vis[i]) {//CCF RP--
			vis[i]=1;//CCF RP--
			if(sum2>=c[i]||a[idx]==0)dfs(idx+1,sum,sum2+1);//CCF RP--
			else dfs(idx+1,sum+1,sum2);//CCF RP--
			vis[i]=0;//CCF RP--
		}//CCF RP--
	}//CCF RP--
}//CCF RP--
signed main() {//CCF RP--
	freopen("employ.in","r",stdin);//CCF RP--
	freopen("employ.out","w",stdout);//CCF RP--
	n=read(),m=read();//CCF RP--
	for(int i=1; i<=n; i++){//CCF RP--
		char c=getchar();//CCF RP--
		a[i]=c-'0';	//CCF RP--
	}//CCF RP--
	for(int i=1; i<=n; i++)c[i]=read();//CCF RP--
	dfs(1,0,0);//CCF RP--
	cout<<ans<<'\n';//CCF RP--
	return 0;//CCF RP--
}
//CCF RP--//CCF RP--//CCF RP--//CCF RP--
//CCF RP--//CCF RP--//CCF RP--//CCF RP--
//CCF RP--
//CCF RP--
//CCF RP--
//CCF RP--
//CCF RP--
//CCF RP--//CCF RP--//CCF RP--
//CCF RP--//CCF RP--//CCF RP--
//CCF RP--
//CCF RP--
//CCF RP--
//CCF RP--
//CCF RP--
//CCF RP--
//CCF RP--

//CCF RP--			//CCF RP--
//CCF RP--			//CCF RP--
//CCF RP--			//CCF RP--
//CCF RP--			//CCF RP--
//CCF RP--			//CCF RP--
//CCF RP--			//CCF RP--
//CCF RP--			//CCF RP--
//CCF RP--			//CCF RP--
	//CCF RP--//CCF RP--
	//CCF RP--//CCF RP--