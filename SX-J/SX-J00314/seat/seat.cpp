#include<bits/stdc++.h>
using namespace std;
long long a[10005];
long long b[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,j,k,n,m,c,r,w,h,p,q,sum=0;
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(j=1;j<=n*m;j++){
		b[j]=a[j];
		if(b[j]==k){
			w=j;
		}
	}
	for(h=1;h<=m;h++){
		if(n%2==1){
			for(p=1;p<=n;p++){
				sum++;
				if(w==sum){
					break;
				}
			}
		}
		else{
			for(q=n;q>=1;q--){
				sum++;
				if(w==sum){
					break;
				}
			}
		}
	}
	c=m;
	r=n;
	cout<<c<<' '<<r;
	return 0;
}