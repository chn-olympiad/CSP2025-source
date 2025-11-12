#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m],ai,at=0,bm=1;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}ai=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(ai==a[i]){
			at=i+1;
		}
	}
	at=m*n-at+1;
	while(at>0){
		if(at<=n){
			cout<<bm<<" ";
			if(bm%2==1){
			    cout<<at;
		    }else{
		    	cout<<n-at+1;
			}return 0;
		}
		at-=n;
		bm++;
	}
}
