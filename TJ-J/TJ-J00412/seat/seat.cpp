#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++) cin>>a[i];
	int r;
	r = a[0];
	sort(a,a+n*m,cmp);
	int k;
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			k=i+1;
			break;
		}
	}
	int p,q;
	p=(k%n==0)?k/n:k/n+1;
	q=(p%2==0)?(n-k%n+1):((k==n)?n:k%n);
	cout<<p<<" "<<q;
	return 0;
} 
