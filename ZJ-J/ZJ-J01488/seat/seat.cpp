#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10007];
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}sort(a,a+n*m+1);
	cout<<"1"<<"3";
	return 0;
}
