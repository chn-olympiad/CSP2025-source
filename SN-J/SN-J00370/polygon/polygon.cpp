#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],cnt;
void dfs(long long x,long long y,long long z,long long q,int w){
	if(x>n){
		return ;
	}
	if(y>=3&&w&&z>q*2){
		cnt++;
	}
	dfs(x+1,y,z,q,0);
	dfs(x+1,y+1,z+a[x],max(q,a[x]),1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		if(a[0]+a[1]+a[2]>max(a[0],max(a[1],a[2]))*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	dfs(0,0,0,0,1);
	cout<<cnt%998244353;
	return 0;
}
