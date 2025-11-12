#include<bits/stdc++.h>
using namespace std;
int b[250];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int a1=b[1],s;
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i] == a1){
			s=i;
		}
	}
	int sum1=s/n,sum2=s%n;
	if(sum1%2!=0){
		if(sum2==0) cout<<sum1<<' '<<n;
		else cout<<sum1+1<<' '<<n-sum2+1;
	}
	else{
		if(sum2==0) cout<<sum1<<' '<<1;
		else cout<<sum1+1<<' '<<sum2;
	}
	return 0;
}
