#include <iostream>
#include <cstdio>
using namespace std;
int n,m,c[510];
int f[110][110][110];
string s;
bool st[510];
int dfs(int pas,int rt,int k){
//	if(pas==2) cout<<pas<<" "<<rt<<" "<<k<<" "<<"\n";
	if(k==n+1){
		if(pas>=m) return 1;
		return 0;
	}
	int ret=0;
	bool p[520];
	int grt=rt;
	for(int i=1;i<=n;i++){
		if(grt>=c[i]&&st[i]==0){
			p[i]=1;
//			cout<<"G"<<i<<"\n";
//			st[i]=1;
			rt++;
		}
	}
	if(s[k-1]=='0'){
		for(int i=1;i<=n;i++){
			if(st[i]==0){
				st[i]=1;
				if(p[i]) ret+=dfs(pas,rt,k+1);
				else ret+=dfs(pas,rt+1,k+1);
				st[i]=0;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(st[i]==0){
				st[i]=1;
				if(p[i]) ret+=dfs(pas,rt,k+1);
				else ret+=dfs(pas+1,rt,k+1);
				st[i]=0;
			}
		}
	}
//	cout<<pas<<" "<<rt<<" "<<k<<" "<<ret<<"\n";
	return ret;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	cout<<dfs(0,0,1);
	return 0;
}
//10 5
//1101111011
//6 0 4 2 1 2 5 4 3 3
