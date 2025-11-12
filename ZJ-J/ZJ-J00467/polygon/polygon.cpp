#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,num,a[505];
bool b=true;
void dfs(int x,int y,int z,int xx){
	if(x==n+1){
		if(y*2<z&&xx>=3)num++;
		return;
	}
	dfs(x+1,y,z,xx);
	dfs(x+1,max(y,a[x]),z+a[x],xx+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    if(a[i]!=1)b=false;
	}
	if(b==true){
		long long num=1;
		for(int i=1;i<=n;i++)
		    num=num*2%mod;
		cout<<(num-1-n-n*(n-1)/2+mod*2)%mod;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<num;
	return 0;
}
