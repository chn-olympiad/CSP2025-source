#include<bits/stdc++.h>
#define ull unsigned long long
#define Spa putchar(' ')
#define Nxt puts("")
#define raed read
namespace FastIO{
	inline int read(int &x){
		x=0;
		char c=getchar();
		bool f=0;
		while(!isdigit(c)){
			if(c=='-')f=1;
			c=getchar();
		}
		while(isdigit(c)){
			x=(x<<3)+(x<<1)+(c-'0');
			c=getchar();
		}
		return x;
	}
	inline void write(int x){
		int top=0;
		int st[25];
		do{
			st[++top]=x%10;
			x/=10;
		}while(x);
		while(top)putchar(st[top--]+'0');
		return ;
	}
	void tomax(int &x,int y){
		if(x<y)x=y;
		return ;
	}
	void tomin(int &x,int y){
		if(x>y)x=y;
		return ;
	}
}
using namespace FastIO;
using namespace std;
const int N=2e5+5,M=5e6+5,base=233;
int n,q,L1,L2;
char c[2][M];
int len[N];
ull hsh[N][2],pw[M],pre[2][M];
ull gethash(int opt,int l,int r){ 
	return pre[opt][r]-pre[opt][l-1]*pw[r-l+1];
}
namespace Subtask1{
void solve(){
	
}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace3.in","r",stdin);
	read(n),read(q);
	pw[0]=1;
	for(int i=1;i<=2500000;i++)pw[i]=pw[i-1]*base;
	for(int i=1;i<=n;i++){
		scanf("%s",c[0]+1);
		scanf("%s",c[1]+1);
		len[i]=strlen(c[0]+1);
		for(int j=1;j<=len[i];j++){
			hsh[i][0]=hsh[i][0]*base+c[0][j];
			hsh[i][1]=hsh[i][1]*base+c[1][j];
		}
	}
	while(q--){
		scanf("%s",c[0]+1);
		scanf("%s",c[1]+1);
		if(strlen(c[0]+1)!=strlen(c[1]+1)){
			puts("0");
			continue;
		}
		int mx=strlen(c[0]+1),ans=0;
		for(int i=1;i<=mx;i++){
			pre[0][i]=pre[0][i-1]*base+c[0][i];
			pre[1][i]=pre[1][i-1]*base+c[1][i];
		}
		for(int i=0;i<=mx;i++){
			if(i&&c[0][i]!=c[1][i])break;
			for(int j=1;j<=n;j++){
				if(i+len[j]>mx)continue;
				if(gethash(0,i+1,i+len[j])!=hsh[j][0])continue; 
				if(gethash(1,i+1,i+len[j])!=hsh[j][1])continue; 
				if(gethash(0,i+len[j]+1,mx)!=gethash(1,i+len[j]+1,mx))continue; 
				ans++;
			}
		}
		write(ans),Nxt;
	}
}
