#include<bits/stdc++.h>
using namespace std;
vector<int> wood;
int ans;
void plg(int sum,int mxv,int csw,int stt){
	for(int i=stt;i<wood.size();i++)
		plg(sum+wood[i],max(mxv,wood[i]),csw+1,i+1);
	if(csw>2&&sum>mxv*2) ans=(ans+1)%998244353;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	wood.resize(n);
	for(int i=0;i<n;i++) cin>>wood[i];
	plg(0,0,0,0);
	cout<<ans;
} 
