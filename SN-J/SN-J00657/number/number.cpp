#include<bits/stdc++.h>
using namespace std;
string mys;
vector<long long>a;
long long lentt;
bool cmp(long long qqqx,long long qqqy){
	return qqqx>qqqy;
}
int main(){
	//SN-J00657 Lianglinyi TYQJ
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>mys;
	lentt=mys.size();
	for(long long i=0;i<lentt;i++){
		if(mys[i]>='0'&&mys[i]<='9'){
			a.push_back(mys[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(auto f:a){
		cout<<f;
	}
	return 0;
}
