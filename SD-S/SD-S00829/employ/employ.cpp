#include<bits/stdc++.h>
using namespace std;
string s;
const int N=505+5;
const int mod=998244353;
long long n,m,c[N],a[N],cnt,pos,sum,ans,vis[N];
void bfs(int stepp){
     if(stepp==n) {sum=0;
	 for(int i=1;i<=n;i++){
	 	if(c[a[i]]<=sum||s[i]=='0') sum++;
	 	else continue;
	 }
     if(sum<=n-m) ans++;	 
	 return;}
     for(int i=1;i<=n;i++){
     	if(vis[i]) continue;
		 vis[i]=1;
     	a[stepp+1]=i;
     	bfs(stepp+1);
     	vis[i]=0;
	 }
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	cin>>c[i];
	bfs(0);
	cout<<ans;
	return 0;
} 
