#include<bits/stdc++.h>
using namespace std;
int n,m,s,p,r;
int a[1010];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int q=n*m;
	for (int i=0;i<q;i++){
		cin>>a[i];
	}
	int c=a[0];
	sort(a,a+q,cmp);
	for (int i=0;i<q;i++){
		if(a[i]==c) s=i;
	}
	s++;
	if(s%n!=0) p++;
	p=p+s/n;
	if(p%2==0) r=n-s%n+1;
	else r=s%n;
	if(r==0) r=n;
	cout<<p<<" "<<r;
	return 0;
}

