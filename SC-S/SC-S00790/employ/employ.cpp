#include <bits/stdc++.h>
using namespace std;
const int P=998244353;

int n,m,tmp;
long long ans;
char dif[501];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>dif[i];
		if(dif[i]=='1'){
			tmp++;
		}
	}
	if(tmp==n){//case 6~8 16~17
		ans=1;
		for(int i=1;i<=m;i++){
			ans=ans*i%P;
		}
	}
	
	cout<<ans;
	return 0;
}