#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	int x=a[1];
	//cout<<x;
	sort(a+1,a+nm+1);
	int sum=0;
	for (int i=1;i<=nm;i++){
		sum+=1;
	    if(a[i]==x){
			break;
		}
	}
	//cout<<sum;
	int zq=nm+1;
	zq-=sum;
	//cout<<zq;
	int sh=zq/m;//求出商
	int ys=zq%m;//求余数
	//cout<<m+1-ys;
	if (sh%2==0){
		if(ys==0){
			cout<<sh<<" "<<1;
		}
		if(ys!=0){
			cout<<sh+1<<" "<<ys;
		}
	}
	if (sh%2==1){
		if(ys==0){
			cout<<sh<<" "<<m;
		}
		if(ys!=0){
			cout<<sh+1<<" "<<m+1-ys;
		}
	}
	return 0;
} 
