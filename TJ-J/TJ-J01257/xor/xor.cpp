#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll R[500005],n,k;
int main(){
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++)cin>>R[i];
	int qjh = R[1],ans;
	if(qjh == k){
		ans++;
		qjh = 0;
	}
	for(int i = 2;i<=n;i++){
		qjh^=R[i];
		if(qjh == k){
			ans++;
			qjh = 0;
		}
	}
	cout<<ans;
	return 0;
}
