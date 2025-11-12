#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream cin("seat.in");
	ofstream cout("seat.out");
	long long n,m;
	cin>>n>>m;
	priority_queue<long long>a;
	long long b;
	cin>>b;
	a.push(b);
	for(long long i=1;i<n*m;i++){
		long long x;
		cin>>x;
		a.push(x);
	}
	long long p=1;
	for(long long i=1;i<=n*m;i++){
		if(a.top()!=b){
			p++;
			a.pop();
		}
		else{
			break;
		}
	}
	long long c,r;
	c=(p-1)/n+1;
	if(c%2==1){
		r=(p-1)%n+1;
	}
	else{
		r=n-(p-1)%n;
	}
	cout<<c<<' '<<r;
	
}
