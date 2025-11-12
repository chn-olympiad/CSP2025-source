#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,a[505]={};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int sum=0,x[105]={},y[105]={};
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
			x[++sum]=i;
			y[sum]=j;
			}
		}
		else{
			for(int j=1;j<=n;j++){
			x[++sum]=i;
			y[sum]=j;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			cout<<x[i]<<" "<<y[i];
			return 0;	
		}
	}
	return 0;
}
