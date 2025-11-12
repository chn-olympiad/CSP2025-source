#include<bits/stdc++.h>

using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	string s;
	vector<int>S;
	cin>>s;
	for(auto x:s){
		if('0'<=x&&x<='9'){
			S.push_back(x-'0');
		}
	}
	sort(S.begin(),S.end(),cmp);
	for(auto x:S){
		cout<<x;
	}
	return 0;
}
/*
ccf is really good,so please to give me 1=.
感觉预期324，可能会高一点
I love ccf!!!!!!!!!!!!
*/
