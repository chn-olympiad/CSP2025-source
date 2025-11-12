#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	vector <int> v;
	for (int i=0;i<a.size();i++) {
		if (a[i]>='0' && a[i]<='9') {
			v.push_back(a[i]-'0');
		}
	}
	sort(v.begin(),v.end(),cmp);
	for (int i=0;i<v.size();i++) {
		cout<<v[i];
	}
	return 0;
}
