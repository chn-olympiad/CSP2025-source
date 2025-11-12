#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[10005],g,x;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	x=a[0];
	for(int i=0;i<=n*m-1;i++){
		for(int j=0;j<=n*m-2;j++){
			if(a[j]<a[j+1])
			swap(a[j],a[j+1]);
		}
	}
	for(int i=0;i<=n*m;i++){
		if(a[i]==x){
			g=i;
		}
	}
	int h=1,l=1,f=0,ll=0;
	while(g--){
	if(f==0 and ll==0){
		h++;    
	}else if(f==1 and ll==0){
		h--;
	}else if(f==1 and ll==1){
		l++;
		ll=0;
		continue;
	}else if(f==0 and ll==1){
	    l++;
	    ll=0;
	    continue;
	}	
		if(h==n){
		f=1;
		ll=1;
		}	
		if(h==1){
			f=0;
			ll=1;
		}
	}
	cout<<l<<" "<<h;
	return 0;
} 
