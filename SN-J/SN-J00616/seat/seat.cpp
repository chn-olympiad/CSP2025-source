#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,aaa=1,aa,yi;
	int a[105],x[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
	}
	yi=x[1];
	sort(x+1,x+n*m+1);
	for(int i=n*m;i>=1;i--){
		a[i]=x[aaa];
		aaa++;
	}
	for(int i=1;i<=n*m;i++){
		if(yi==a[i]){aa=i;
		}
	}
	if((aa/n)%2==0||((aa/n)-1==(aa-1)/n)&&((aa/n)-1)%2==0){
		if(aa%n!=0)	cout<<aa/n+1<<" ";
		else cout<<aa/n<<" ";
		if(aa%n!=0) cout<<aa%n;
		else cout<<n;
	}
	else if((aa/n)%2==1||((aa/n)-1==(aa-1)/n)&&((aa/n)-1)%2==1&&aa!=m){
		if(aa%n!=0)	cout<<aa/n+1<<" ";
		else cout<<aa/n<<" ";
		if(aa%n!=0) cout<<n-aa%n+1;
		else cout<<1;
	}
	return 0;
}
