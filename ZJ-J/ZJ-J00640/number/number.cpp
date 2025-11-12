#include<bits/stdc++.h>
using namespace std;
string s;
vector <int> a;

bool cmp(int x,int y){
	return x>y;
}

void solve(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		char j=s[i];
		if(j>='0'&&j<='9')
			a.push_back(j-'0');
	}
	sort(a.begin(),a.end(),cmp);
	for(auto i:a)
		cout<<i;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int T=1;
	while(T--)
		solve();
		
	return 0;
}

