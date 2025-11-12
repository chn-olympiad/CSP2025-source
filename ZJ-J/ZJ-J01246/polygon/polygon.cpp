#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int>dk;
	int maxx=0;
	int ones=0;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		dk.push_back(k);
		maxx=max(maxx,k);
	}
	
	long long ans=0;

	if(n==3 && maxx>1){
		if(2*(max(max(dk[0],dk[1]),dk[2]))<dk[0]+dk[1]+dk[2]){
			ans++;
		}
	}
	if(n==3 && maxx==1){
		cout<<1<<endl;
		return 0;
	}
	cout<<ans<<endl;
}
