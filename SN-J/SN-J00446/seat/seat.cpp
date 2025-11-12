#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,t;
int cnt(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int ans=n*m;
	
	for(int i=1;i<=ans;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+ans+1,cnt);
	for(int i=1;i<=ans;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	if(r%n==0){
		s=r/n;
	}else{
		s=r/n+1;
	}
	int u=r-n*(s-1);
	if(s%2==0){
		t=n-u+1;
	}else{
		t=u;
	}
	cout<<s<<" "<<t;
	return 0;
}
