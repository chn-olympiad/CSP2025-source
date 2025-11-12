#include<bits/stdc++.h>

using namespace std;
long long n,m,q,s=0,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	q=n*m;
	long long a[q];
	for(long long i=0;i<q;i++){
		cin>>a[i];
		if(a[0]<a[i]){
			++s;
		}
	}s+=1;
	if((s/n+1)%2==1){
		cout<<(s/n)+1<<' '<<s%n;	
	}else{
		cout<<(s/n)+1<<' '<<n-(s%n)+1;
	}
}
