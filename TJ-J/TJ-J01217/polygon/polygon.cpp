#include<iostream>
using namespace std;
int n,a[5005];
int num=3;
int v;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; ++i){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	while(num<=n){
		for(int i=1; i<=n-num; ++i){
			int cnt=0,maxx=0;
			for(int j=i; j<=i+num; ++j){
				cnt+=a[j];
				maxx=max(maxx,a[j]);
			}
			if(cnt>2*maxx){
				v++;
			}
			v=v%998244353;
		}
		num++;
	}
	cout<<v*3;
	return 0;
}
