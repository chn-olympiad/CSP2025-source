//SN-J00760 王晨希 西安铁一中
#include<bits/stdc++.h>
using namespace std;
long long a[1001];
long long n,m;
long long ans=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cout<<n<<m;
	return 0;
}
