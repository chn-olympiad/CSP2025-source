#include<bits/stdc++.h>
using namespace std;
bool c(int a,int b){
	return a>b;
}
int a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,c);
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<' ';
	cout<<endl;
	int l=1;
	int r=n*m;
	int mid=0;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]>R)l=mid+1;
		else if(a[mid]<R)r=mid-1;
		else break;
	}
	//cout<<mid<<endl;
	int lie;
	
	if(mid%n==0)lie=mid/n;
	else lie=mid/n+1;
	
	int hang,num=mid-(lie-1)*n;
	//cout<<num<<endl;
	if(lie%2==0)hang=n-num+1;
	else hang=num;
	
	cout<<lie<<' '<<hang;
	return 0;
}

