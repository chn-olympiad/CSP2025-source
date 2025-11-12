#include<bits/stdc++.h>
using namespace std;
const int N=1e6+4;
vector<int>vec;
string s;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		char c=s[i];if('0'>c||c>'9') continue;
		vec.push_back(c-'0');
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i:vec) cout<<i;
	return 0;
}
