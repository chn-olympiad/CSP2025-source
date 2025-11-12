#include<bits/stdc++.h>
using namespace std;
int a[205]={};
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int n,m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int id;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			id=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		cnt++;
		if(a[i]==id){
			break;
		}

	}
	int l;
	l=(cnt+n-1)/n;
	cout<<l<<" ";
	if(l%2==1){
		if(cnt%n==0)cout<<cnt;
		else
		cout<<cnt%n;
	}
	else{
		if(cnt%n==0)cout<<1;
		else
		cout<<n-cnt%n+1;

	}
	return 0;
}
