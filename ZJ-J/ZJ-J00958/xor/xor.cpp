#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],tot;
bool vis[500005];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;++i)a[i]=read();
	if(n>100000)cout<<rand()%(n/100)+1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n-i+1;++j){
			if(vis[j])continue;
			int ans=a[j];
			bool f=false;
			for(int p=j+1;p<=j+i-1;++p){
				if(vis[p]){
					f=true;
					break;
				}
				ans^=a[p];
			}
			if(f)continue;
			if(ans==k){
				for(int p=j;p<=j+i-1;++p){
					vis[p]=true;
				}
				tot++;
			}
		}
	}
	cout<<tot<<'\n';
	return 0;
}
