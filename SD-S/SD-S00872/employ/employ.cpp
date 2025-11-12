#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=505;
const int N=998244353;
bool s[MAXN];
int c[MAXN];
bool p[MAXN]={0};
int ans=0;
void dfs(int day,int f){
	if(f>n-m) return ;
	if(day>n){
		ans++;
	}
	for(int i=1;i<=n;i++){
		if(c[i]=f){
			p[i]=1;
		}
		if(p[i]==0){
			p[i]=1;
			if(s[day]){
				dfs(day+1,f);
			}
			else{
				dfs(day+1,f+1);
			}
			p[i]=0;
		}
	}
	for(int i=1;i<=n;i++){
			if(c[i]=f){
			p[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool t;
	for(int i=1;i<=n;i++){
		t=getchar();
		bool temp;
		if(t=='0') temp=0;
		else temp=1;
		s[i]=temp;
	} 
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
