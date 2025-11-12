#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n,a[N],k,cnt_1,cnt_0,cnt_11,vis;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt_1++;
		}
		else if(a[i]==0){
			cnt_0++;
		}
		if(a[i-1]==1&&a[i]==1&&vis==0){
			cnt_11++;
			vis=1;
		}
		else vis=0;
	}
	if(cnt_1==n){
		if(k==1) cout<<n;
		else if(k==0) cout<<n/2;
		else cout<<0;
	}
	else if(cnt_0+cnt_1==n){
		if(k==1) cout<<cnt_1;
		else if(k==0) cout<<cnt_0+cnt_11;
		else cout<<0;
	}else{
		ll cnt=0,ans=0; 
		for(int i=1;i<=n;i++){
			ans^=a[i];
			if(ans==k){
				cnt++;
				ans=0;
			}
		}
		cout<<cnt;
	}
	return 0;
}
