#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],n,k;
int xorr(int x,int y){
	int n=x,m=y; 
	bitset<25> a=n;
	bitset<25> b=m;
	bool ans[25];
	for(int i=0;i<=25;i++){
		if(a[i]!=b[i]) ans[i]=1;
		else ans[i]=0;
	}
//	for(int i=0;i<=25;i++) cout<<ans[i];
	int res=0;
	long long cnt=1;
	for(int i=0;i<=25;i++){
		res+=ans[i]*cnt;
		cnt*=2;
	}
	return res;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		if(a[i]>1) flag=1;
	}
	if(!flag&&k==1){
		cout<<cnt;
		return 0;
	}
//	for(int l=1;l<=n;l++) cout<<b[l]<<" ";
	int ans=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int q=a[l];
			if(r>l) for(int i=l+1;i<=r;i++) q=xorr(q,a[i]);
			if(q==k){
				ans++;
				l=r;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
