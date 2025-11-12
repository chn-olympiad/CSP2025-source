#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int M=998244353;
int n,ans;
int bj[N],a[N],b[N];
void bfs(int k){
	if(k>=3&&k<=n){
		int x=0;
		for(int i=1;i<=k;i++){
			x+=b[i];
		}
		int t=0;
		for(int i=1;i<=k;i++){
			if(x<=b[i]*2){
				t=1;
				break;
			}
		}
		if(t==0){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(bj[i]==0){
			bj[i]=1;
			k++;
			b[k]=a[i];
			bfs(k);
			k--;
			bj[i]=0;
			b[k]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bfs(0);
	cout<<ans%M;
	return 0;
}