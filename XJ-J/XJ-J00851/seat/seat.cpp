#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+5];
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	int p=a[1];
	int k=0;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p)k=n*m-i+1;
	}
	int c=0;
	for(int i=1;i<=m;i++){
		k=k-n;
		if(k<=0){
			k=k+n;
			c=i;
			if(c%2!=0){
		       cout<<c<<" "<<k;
	        }else cout<<c<<" "<<n-k+1;
	        return 0;
		}
	}
	return 0;
}

