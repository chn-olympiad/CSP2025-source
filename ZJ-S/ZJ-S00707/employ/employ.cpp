#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=555;
int read(){
	int x=0,f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(isdigit(s)){
		x=(x<<3)+(x<<1)+(s^48);
		s=getchar();
	}
	return x*f;
}
char s[N];
int n[N];
int q[N];
int a,b;
int ans=0;
bool p[N];
void dfs(int x,int u,int tot){
	if(u>=b){
		ans++;
		return;
	}
	if(x>a)return;
	for(int i=1;i<=a;i++){
		if(p[i])continue;
		p[i]=1;
		if(s[x]=='0'||tot>=n[i]){
			dfs(x+1,u,tot+1);
		}else{
			dfs(x+1,u+1,tot);
		}
		p[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	a=read(),b=read();
	cin>>(s+1);
	for(int i=1;i<=a;i++){
		n[i]=read();
	}
	dfs(1,0,0);
	cout<<ans;
	
	return 0;
}