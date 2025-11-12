#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a,ans;

int main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=3*m;i++){
		cin>>a;
	}
	for(int i=1;i<=n+1;i++){
		cin>>a;
		ans+=a;
	}
	cout<<ans;
} 

