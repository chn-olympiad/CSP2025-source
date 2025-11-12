#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;	
}
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ss=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=0;
	for(int i=1;i<=n*m;i++){
		//cout<<a[i]<<endl;
		if(a[i]==ss) k=i;
	}
	int l=0,r=0;
	if(k%n==0){
		cout<<k/n<<" "<<n<<endl;
		return 0;
	}
	r=k/n+1;
	//cout<<r<<endl<<k<<endl;
	if(r%2==1) l=n-(r*n-k);
	else l=r*n-k;
	cout<<r<<" "<<l<<endl;
	return 0;
}
