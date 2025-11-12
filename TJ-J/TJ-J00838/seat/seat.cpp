#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cj[105]={};
	int r;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	r=cj[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(cj[j]<cj[j+1]){
				int l=cj[j];
				cj[j]=cj[j+1];
				cj[j+1]=l;
			}
		}
	}
	int ans1;
	for(int i=1;i<=n*m;i++){
		if(cj[i]==r){
			ans1=i;
			break;
		}
	}
	int ans,ans0;
	if(ans1%n==0){
		ans=ans1/n;
	}else{
		ans=(ans1/n)+1;
	}
	if(ans1%m==0){
		ans0=n;
	}else{
		if((ans1/m)%2==1){
			ans0=ans1%m+1;
		}else{
			ans0=(ans1-1)%m+1;
		}
	}
	cout<<ans<<' '<<ans0;
	return 0;
}
