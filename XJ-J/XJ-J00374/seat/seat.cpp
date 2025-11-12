#include<bits/stdc++.h>
using namespace std; 
int l[5010];
int n,m,k,j,o=0,p,b,c,r; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>l[i];
	}
	p=l[1];
	for(;;){
		for(int i=1;i<=k-1;i++){
			if(l[i]<l[i+1]){
				j=l[i+1];
				l[i+1]=l[i];
				l[i]=j;
				o++;
			}
		}
		if(o==0){
			break;
		}
		o=0;
	}
	for(int i=1;i<=k;i++){
		if(l[i]==p){
			b=i;
		}
	}
	if(b<=n){
		c=1;
		r=b;
	}else if(b/n%2==0){
		r=b%n;
		c=b/n+1;
	}else if(b/n%2!=0){
		r=4-b%n+1;
		c=b/n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
