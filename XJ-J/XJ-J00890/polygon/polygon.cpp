#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		int s1=1,s2=1;
		for(int j=0;j<i;j++){
			s1*=n-j;
			s2*=j+1;
		}
		sum+=s1/s2;
	}
	cout<<sum/3;
	return 0;
}
