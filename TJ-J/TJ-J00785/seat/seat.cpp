#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
long long n,m,s,b,q;
int c[20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long a[n*m]={};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c[1]=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		s++;
		if(a[i]==c[1]){
			break;
		}
	}
	q=s;
	if(s>n){
		while(s>n){
			s=s-s/n;
			q=q/n+1;
		}
		cout<<s<<" "<<q;
		return 0;
	}
	cout<<1<<" "<<s;
}
