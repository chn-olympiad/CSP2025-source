#include <bits/stdc++.h>
using namespace std;
const int MAXN=500010;
int a[MAXN],n,k,ans,m,t;
int res[MAXN][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	int l=1,r=1;
	ans=a[1];
	while(l<=n){
		while(r<=n-1 && ans!=k){
			r++;
			ans^=a[r];
		}
		if(ans == k && r<=n){
			t++;
			res[t][0]=l;
			res[t][1]=r;
		}else{
			ans^=a[r];
			r=l;
		}
		ans^=a[l++];
		if(r<l){
			r=l;
			ans=a[l];
		}
	}
	
	for(int i=1;i<=t;i++){
		if(res[i][0] > res[i-1][1]) m++;
		cout<<res[i][0]<<" "<<res[i][1]<<" ";
	}
	cout<<m;
	return 0;
}
