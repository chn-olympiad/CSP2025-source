#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[110],x,max,b=0,c;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	for(long long i=1;i<=n*m;i++){
		max=0;
		for(long long j=i;j<=n*m;j++){
		    if(a[j]>max){
		    	max=a[j];
		    	x=j;
			}
	    }
	    swap(a[i],a[x]);
	}
	long long j=1;
	for(long long i=1;i<=n;i++){
		for(;true;){
			if(j>m){
				j=m;
				break;
			} 
			if(j<1){
				j=1;
				break;
			}
			b++; 
		    if(a[b]==c){
		    	cout<<i<<" "<<j;
		    	return 0;
			}
			if(i%2==0) j--;
			else if(i%2!=0) j++;
	    } 
	}
	return 0;
}
