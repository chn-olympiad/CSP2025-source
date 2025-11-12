#include <bits/stdc++.h>
using namespace std;
int n,k,a[500001],r,b[500001];
long long cnt=0,cnt1=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
		}
		cout<<cnt;
		return 0;
	}else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
			else if(a[i]==1&&a[i-1]==1){
				cnt1++;
				i++;
			}
		}
		cout<<cnt+cnt1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]^=a[i-1];
	}
	for(int l=2;l<=n;l++){
		r=lower_bound(a+1,a+1+n,k^a[l])-a;
		if(a[r]^a[l-1]==k&&((b[l]!=0&&!b[r]!=0)||(abs(r-l)>b[l]||abs(l-r)>b[r]))){
			cnt++;
			for(int i=l;i<=r;i++) b[i]=abs(r-l);
		}
	}
	cout<<cnt-1;
	return 0;
}
