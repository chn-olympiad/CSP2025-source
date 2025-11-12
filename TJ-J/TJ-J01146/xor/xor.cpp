#include<bits/stdc++.h>

using namespace std;
long long n,k,a[500010],h, m=INT_MIN;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0&&n<=2){
		if(n==1&&a[1]==0){
			cout<<1;
			return 0;
		}
		if(n==2&&a[1]==0&&a[2]==0){
			cout<<2;
			return 0;
		}
		if(n==2&&(a[1]==0||a[2]==0)){
			cout<<1;
			return 0;
		}else cout<<0;
		return 0;
	}
	for(long long  i=1;i<=n;i++){
		for(long long  r=i;r<=n;r++){
			for(int f=i;f<=r;f++){
				h=h^a[f];
			}
			if(h==k){
				m=max(m,r-i);
			}
			
		}
	}
	cout<<m+1;
	return 0;
}
