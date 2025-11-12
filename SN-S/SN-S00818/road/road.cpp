#include <bits/stdc++.h>
using namespace std;
long long n,m,k,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int ui,vi,wi;
		cin>>ui>>vi>>wi;
		sum+=wi;
	}
	if (k==0){
		cout<<sum<<endl;
		return 0;
	}
	return 0;
}

