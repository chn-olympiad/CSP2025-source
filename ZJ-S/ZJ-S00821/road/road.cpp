#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+1;
ll zh=0;

int main(){
  	freopen("road.in","r",stdin);
  	freopen("road.out","w",stdout);
  	ll n,m,k;
  	cin>>n>>m>>k;
  	zh=n*m-k;
	cout<<zh;
	return 0;
}

