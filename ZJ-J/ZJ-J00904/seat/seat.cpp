#include<bits/stdc++.h>
using namespace std;

const int N=105;
int n,m,sum,a1,num1;
int a[N];

bool cmp(int x1,int x2){
	return x1>x2;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i]==a1){
			num1=i;
		}
	}
	int l,r;//lie hang
	if(num1%n==0)l=num1/n;
	else l=num1/n+1;
	if(l%2==1){
		r=num1%n;
		if(r==0)r=n;
	}
	else{
		if(num1%n==0)r=1;
		r=n-num1%n+1;
	}
	cout<<l<<" "<<r;
	
	cout<<endl;
	

	return 0;
}

