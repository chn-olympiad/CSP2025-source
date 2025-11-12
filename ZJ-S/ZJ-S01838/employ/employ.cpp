#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005],d[600][600];
long long ans;
string s;
bool vis[600];
void ss(int z){
	if(z==n){
		ans++;
		return ;
	}
	for(int i=0;i<n;i++){
		if((s[z]=='0'||a[i]<=z)&&vis[i]==0){
			vis[i]=1;
			ss(z+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(m==1){
		ss(0);
		cout<<ans;
	}
}
