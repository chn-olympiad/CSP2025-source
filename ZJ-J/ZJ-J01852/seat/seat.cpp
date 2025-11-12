#include<bits/stdc++.h>
using namespace std;
int n,m;
int x;
int t;
int a[105];

bool cmp(int k,int y){
	return k>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	x=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			t=i;
			break;
		}
		if(a[n*m-i-1]==x){
			t=n*m-i-1;
			break;
		}
	}
	int s=t/n+1;
	int d;
	if(s%2==0){
		d=n-(t%n);
	}else{
		d=(t%n)+1;
	}
	cout<<s<<" "<<d;
	return 0;
}
