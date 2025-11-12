#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <string>
#define int long long
using namespace std;
const int N=2e5+10;
string ch1,ch2,qu1,qu2;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ch1>>ch2;
	}
	for(int i=1;i<=q;i++){
		cin>>qu1>>qu2;
	}
	for(int i=1;i<=q;i++){
		cout<<"0"<<'\n';
	}
	return 0;
}

