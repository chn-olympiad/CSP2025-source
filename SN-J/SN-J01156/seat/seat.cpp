#include <bits/stdc++.h>
using namespace std;
int n,m,R,s[120],a[12][12];
int x,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
		if(i==1){
			R=s[i];
		}
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==R){
			R=i;
		}
	}
	if(R%n==0){
		if((R/n)%2==0){
			cout<<R/n<<" "<<1;
		}else{
			cout<<R/n<<" "<<n;
		}
	}else{
		if((R/n+1)%2==0){
			cout<<R/n+1<<" "<<n-(R%n)+1;
		}else{
			cout<<R/n+1<<" "<<1+(R%n)-1;
		}
	}
	return 0;
}
