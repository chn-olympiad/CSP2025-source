#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
char s[502]; 
int c[502];
const ll mod=998244353;
ll ans=0;
bool vis[502];
int ch[502];
void check(){
	int cnt=0,ac=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[ch[i]]){
			cnt++;
		}else{
			if(s[i]=='0'){
				cnt++;
			}else{
				ac++;
			}
		}
	}
	if(ac>=m){
		ans++;
	}
}
void fun(int x){
	if(x>n){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ch[x]=i;
			vis[i]=true;
			fun(x+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
//	for(int i=1;i<=n;i++) printf("%c",s[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	bool fA=true;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			fA=false;
			break;
		}
	}
	if(n<=18){//8pts
		fun(1);
	}
	printf("%lld",ans);
	return 0;
} 
