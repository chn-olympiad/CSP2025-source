#include<bits/stdc++.h>
using namespace std;
#define int long long
int mx,n,a[5005],num,md=998244353;
int qp(int b,int c){
	if(c==1)return b%md;
	if(c&1)return qp(b,c-1)*b%md;
	else return qp(b*b%md,c>>1)%md;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		num+=a[i];
		mx=max(mx,a[i]);
	}
	sort(a,a+n);
	if(mx==1)cout<<0;
	else if(n<=3){
		if(a[n-1]*2<num){
			cout<<1;
		}
		else cout<<0; 
	}
	else{
		num=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					if(a[k]<a[i]+a[j]){
						num+=qp(2,n-3)-1;
						num%=md;
					}
				}
			}
		}
		cout<<num;
	}
	return 0;
}
