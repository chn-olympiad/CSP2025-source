#include<bits/stdc++.h>
using namespace std;
int n,m,vi[10050];
long long cnt=1;
string ai;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>ai;
	int vis=0;
	for(int i =1;i<=n;i++){
		cin>>vi[i];
		if(!vi[i]){
			vis++;
		}
	}
	for(int i =1;i<=n-vis;i++)cnt*=i,cnt%=998244353;
	cout << cnt;
	return 0;
}
