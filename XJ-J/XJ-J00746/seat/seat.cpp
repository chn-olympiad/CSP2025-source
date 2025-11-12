#include<bits/stdc++.h>
using namespace std;
int n,m,r,a[105],l=0,s=0,t=0,k,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			s=i;
			break;
		}
	}
	s=n*m-s+1;
	for(int i=1;i<=m;i++){
		if(s<=i*m){
			cout<<i<<" ";
			break;
		}
	}
	t=m*2;
	k=s%t;
	for(int i=1;i<=t;i++){
		if(k==i){
			if(k>m){
				k=k-m;
				p=m-k+1;
				cout<<p;
				return 0;
			}
			cout<<i;
			return 0;
		}
	}
	return 0;
}


