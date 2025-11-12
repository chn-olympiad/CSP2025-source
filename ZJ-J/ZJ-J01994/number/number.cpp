#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x0 XA_0
#define y0 YA_0
#define x1 XA_1
#define y1 YA_1
vector<int>v;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back((int)(s[i]-'0'));
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		cout<<v[i];
	}
	return 0;
}
