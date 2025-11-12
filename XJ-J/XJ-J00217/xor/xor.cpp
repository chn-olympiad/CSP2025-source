#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],n,k,cnt=0;
int query(int ll, int rr){
	int cnt=a[ll];
	for(int i=ll+1;i<=rr;i++){
		cnt=a[i]^a[i-1];
	}
	return cnt;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int r=1;r<=n;r++){
		for(int l=r;l<=n;l++){
			for(int kk=l;kk<=r;k++) if(query(l,kk)==k&&query(kk,r)==k) cnt+=2;
		}
	} 
	cout<<cnt;
}
