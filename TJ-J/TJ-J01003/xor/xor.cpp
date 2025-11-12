#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],t,ans;
bool vis[500005],op;
int xo(int x,int y){
	if(x!=y){
		return (x|y)-(x&y);
	}
	else{
		return x;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			t=a[i];
			for(int l=i;l<=j;l++){
				if(vis[l]) op=1;
			}
			if(op){
				op=0;
				break;
			}
			for(int l=i+1;l<=j;l++){
				t=xo(t,a[l]);
			}
			if(t==k){
				ans++;
				for(int l=i;l<=j;l++){
					vis[l]=1;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
