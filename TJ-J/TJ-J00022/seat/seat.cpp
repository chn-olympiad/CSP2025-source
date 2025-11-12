#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c,a;
	cin>>c;
	int sum=0;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>c){
			sum++;
		}
	}
	int u=sum/n;
	cout<<u+1<<' ';
	int p=sum%n;
	if(u%2==0){
		cout<<p+1;
	}
	else{
		cout<<n-p;
	}
	return 0;
}
