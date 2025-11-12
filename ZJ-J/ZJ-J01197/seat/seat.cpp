#include<bits/stdc++.h>
using namespace std;
int n,m;
int xr;
vector<int> a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		if(i==1) xr=x;
		a.push_back(x);
	}
	sort(a.begin(),a.end(),[](int x,int b){
		return x>b;
	});
	int seat=0;
	for(auto val:a){
		if(val==xr) break;
		seat++;
	}
	int s=seat/n;
	int s2=seat%n;
	cout<<s+1<<" ";
	if(s%2) cout<<n-s2;
	else cout<<s2+1;
	return 0;
}
