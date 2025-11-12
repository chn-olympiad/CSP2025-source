#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
string a;
ll n;
vector<ll> num;
bool cmp(ll a,ll b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(ll i=0; i<n; i++) {
		if(a[i]=='0') num.push_back(0);
		else if(a[i]=='1') num.push_back(1);
		else if(a[i]=='2') num.push_back(2);
		else if(a[i]=='3') num.push_back(3);
		else if(a[i]=='4') num.push_back(4);
		else if(a[i]=='5') num.push_back(5);
		else if(a[i]=='6') num.push_back(6);
		else if(a[i]=='7') num.push_back(7);
		else if(a[i]=='8') num.push_back(8);
		else if(a[i]=='9') num.push_back(9);
		else continue;
	}
	sort(num.begin(),num.end(),cmp);
	for(ll i=0; i<num.size(); i++) {
		cout<<num[i];
	}
	return 0;
}
