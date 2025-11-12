#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int r;
int cnt;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		cnt++;
		if(a[i]==r)break;
	}
	int x=(cnt+n-1)/n,y;
	if(x%2){
		if(cnt%n)y=cnt%n;
		else y=n;
	}
	else{
		if(cnt%n)y=n-cnt%n+1;
		else y=n;
	}
	cout<<x<<" "<<y;
	return 0;
	
}