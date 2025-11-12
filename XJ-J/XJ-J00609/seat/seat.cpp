#include<bits/stdc++.h>

using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int n,m,a[10005],a1;
	cin>>n>>m;
	cin>>a1;
	a[0]=a1;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m+1,cmp);
	int l=0,r=n*m;
	while(a1!=a[l]){
		int mid=(l+r)/2;
		if(a[mid]<a1){
			r=mid+1;
		}
		else{
			l=mid;
		}
	}
	int i=l;

	if(int(ceil((double(i)+1.0)/n))%2==0){
		
		cout<<int(ceil((double(i)+1.0)/n))<<' '<<n-(i+1)%n+1;
	}
	else{
		cout<<int(ceil((double(i)+1.0)/n))<<' '<<(i)%n+1;
	}
		
	
	return 0;
}
