#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500;

int n,m,c[N],ans,ss[N],nc[N];
char s[N];
bool b[N];

int check(){
	int pl=0,res=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')pl++;
		else{
			if(pl>=nc[i])pl++;
			else{
				res++;
			}
		}
	}
	return res;
}

void dfs(int x){
	if(x>n){
		if(check()>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			nc[x]=c[i];
			dfs(x+1);
			b[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		ss[i]=1-(s[i]-'0');
		ss[i]+=ss[i-1];
	}
	if(n<=18){
		dfs(1);
		printf("%lld",ans);	
	}
	else{
		printf("0");	
	}
} 
