#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	long long sum=m;
	for(int i=0;i<n;i++)
		sum*=m;
	cout<<sum;
	return 0;
}
