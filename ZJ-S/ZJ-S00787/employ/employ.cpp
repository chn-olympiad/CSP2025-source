//我爱芙宁娜
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f=ch=='-'?-f:f,ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=182376;
int n,m,c[N],p[N],ans;
string str;
bool vis[N];
void DFS(int x){
	if(x==n){
		int num=0,fail=0;
		for(int i=0;i<n;i++){
			if(str[i]=='1'&&fail<c[p[i+1]])num++;
			else fail++;
		}
		if(num>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[x+1]=i;
			DFS(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	if(n>11){
		cout<<0<<endl;
		return 0;
	}
	cin>>str;
	for(int i=1;i<=n;i++)c[i]=read();
	DFS(0);
	cout<<ans<<endl;
	return 0;
}//Luogu user :I_Love_Furina
//Luogu uid 1113349
//Genshin Impact uid 275713829
//Fuirna!!!
//RP++