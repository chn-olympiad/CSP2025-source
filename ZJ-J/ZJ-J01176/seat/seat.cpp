#include<bits/stdc++.h>
using namespace std;
bool cap(int q,int e){
	return q>e;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[200],j=0,sum,p;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			cin>>a[++j];
			if(j==1) p=a[j];
		}
	}
	sort(a+1,a+1+j,cap);
	for(int i=1;i<=j;i++){
		if(a[i]==p){
			sum=i;
			break;
		}
	}
	cout<<ceil(sum*1.0/n)<<" ";
	sum=(sum-1)%(2*n);
	if(sum>=n) cout<<2*n-sum;
	else cout<<sum+1;
	return 0;
}
