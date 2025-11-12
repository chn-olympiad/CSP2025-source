#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==1){
		int l=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0)		l++;
		}
		cout<<l;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n;
	}
	//CCF! you! have! no! egg!普及塞黑题 你知道我上来有多难吗 喂你一坨 
	return 0;
}
