#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int a[10000];
int b[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]&&abs(a[1]-a[2])<a[3]&&abs(a[2]-a[3])<a[1]&&abs(a[1]-a[3])<a[2])
			cout<<1<<endl;
		else cout<<0;
		return 0;
	}
	return 0;
}

