#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],sum,xx=1,yy=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1);
	int i=n*m;
	while(a[i]!=sum){
		if(xx%2==1&&yy<n){
			yy++;
		}else if(xx%2==1&&yy==n){
			xx++;
		}else if(xx%2==0&&yy>1){
			yy--;
		}else{
			xx++;
		}
		i--;
	}
	cout<<xx<<" "<<yy;
	return 0;
}
