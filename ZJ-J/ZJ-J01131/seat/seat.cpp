#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N],x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	x=a[0];
	sort(a,a+n*m,greater<int>());
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			y=i+1;
			break;
		}
	}
	int ans1=y/n+(y%n!=0),ans2=(y%n==0?n:y%n);
	if(ans1%2==0){
		ans2=n+1-ans2;
	}
	cout<<ans1<<" "<<ans2<<endl;;
	return 0;
}
