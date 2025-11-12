#include<bits/stdc++.h>
using namespace std;
int m,n,a[1000],b[1000],num,k;
bool cmp(int x,int y){
	return a[x]>a[y];
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=i;
	}
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==1){
			num=i;
			break;
		}
	}
	k=(num-1)/n+1;
	num=(num-1)%n+1;
	cout<<k<<" ";
	k=k%2;
	if(k){
		cout<<num;
	}
	else{
		cout<<n-num+1;
	}
	return 0;
}