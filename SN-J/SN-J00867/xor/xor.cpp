#include <bits/stdc++.h>
using namespace std;
//priority_queue<int,vector<int>,less<int> >q;
long long a[5100000],n,m,b[5100000],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	long long maxx=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j>maxx;j--){
			if((b[i]^b[j-1])==m){
				maxx=j;
				ans++;
			}
		} 
	}
	cout<<ans; 
	return 0;
}
