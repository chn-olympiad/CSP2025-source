#include <bits/stdc++.h>
using namespace std;
int main(){	
	int n,m,s,b,q;
	cin>>n>>m;
	s=n*m;
	int a[s];
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+s+1);
	for(int i=1;i<=s;i++){
		if(a[i]=b){
			q=i;
		}
	}
	int c,r;
	c=q/n;
	r=q%n;
	if(c==0){	
		c=1;
	}
	if(r==0){
		r=m;
	}
	cout<<c<<" "<<r;
	return 0;
}

