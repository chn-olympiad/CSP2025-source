#include<bits/stdc++.h>

using namespace std;
long long  n,a[5010],m=INT_MIN,h,d;//m=max h=ºÍ d=anser 

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int l=1;l<n-2;l++){
		for(int r=l+2;r<=n;r++){
			h=0,m=INT_MIN;
			
			for(int s=l;s<=r;s++){
				h+=a[s];
				m=max(a[s],m);
			}
			if(h>2*m){
				d++;
				d%=998244353;
			}
		}
	}
	cout<<d*2;
	return 0;
}
