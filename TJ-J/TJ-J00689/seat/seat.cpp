#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[111]={0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x;
	cin>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	int xi;
	for(int i=1;i<=n*m;i++){
		//cout<<a[i]<<endl;
		if(a[i]==x){
			xi=i;
			break;
		}
	}
	//cout<<xi<<endl;
	xi=m*n-xi+1;
	//cout<<xi<<endl;
	int xm;
	if(xi%n==0) xm=xi/m;
	else xm=xi/m+1;
	//cout<<xm<<endl;
	if(xm%2==1){
		cout<<xm<<' '<<(xi-1)%n+1;
	}else{
		cout<<xm<<' '<<n-((xi-1)%n+1)+1;
	}
	return 0;
}
