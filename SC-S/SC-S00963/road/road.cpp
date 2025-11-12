#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>,int> st;
int n,k;
long long sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
	    int a,b,c;
		cin>>a>>b>>c;
		sum+=c;
	}
	cout<<sum;
	return 0;
}