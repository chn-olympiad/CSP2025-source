#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,a[500010],s[500010],vis[500010],ans;
int cnt;
int f(int x,int y){
	int ret=0,g=1;
	while(x||y){
		if(x%2!=y%2)ret+=g;
		g*=2;
		x/=2,y/=2;
		
	}return ret;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int h=0;
		for(int j=i;j<=n;j++){
			if(vis[j]==0)h=f(a[j],h);
			else break;
			if(h==k){
				ans++;
				for(int k=i;k<=j;k++)vis[k]=1;
				//cout<<i<<" "<<j<<"\n";
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
