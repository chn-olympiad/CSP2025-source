#include<bits/stdc++.h>
using namespace std;
int sc[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,ap;
	cin>>n>>m;
	int sum=n*m;
	for(i=0;i<sum;i++){
		cin>>sc[i];
	}
	ap=sc[0];
	sort(sc,sc+sum,greater<int>());
	int l=0,r=sum-1,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(sc[mid]>ap) l=mid+1;
		else if(sc[mid]<ap) r=mid-1;
		else {
			r=mid;break;
		}
	}
	m=r/n+1;
	cout<<m<<" ";
	if(m%2==0){
		cout<<n-r%n;
	}
	else{
		cout<<r%n+1;
	}
	return 0;
}

