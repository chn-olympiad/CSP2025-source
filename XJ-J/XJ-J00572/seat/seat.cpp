#include<bits/stdc++.h>
using namespace std;
int n,m,ans,q,c=1,r=1,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	q=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])ans++;
	}
	if(ans==0){
		cout<<1<<" "<<1;
		return 0;
	}
	c=c+ans/n;
	if(c%2==1){
		r=ans%n+r;
	}else{
		r=n-ans%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
