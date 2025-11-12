#include<bits/stdc++.h>
#include<cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;

int n,m,b[101],ans1,ans2;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	cin>>b[1];
	int b_=b[1];
	rep(i,2,n*m) cin>>b[i];
	sort(b+1,b+1+n*m,cmp);
	rep(i,1,n*m) if(b[i]==b_){
		if(i%n==0) ans1=n;
		else ans1=i%n;
		if(i%n==0) ans2=i/n;
		else ans2=(i-i%n)/n+1;
		continue;
	}
	if(ans2%2==0) cout<<ans2<<" "<<n-ans1+1;
	else cout<<ans2<<" "<<ans1;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
