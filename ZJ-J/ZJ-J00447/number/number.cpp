#include <bits/stdc++.h>
using namespace std;
//priority_queue<int> q;
//priority_queue<int,vector<int> ,greater<int> > q;
string cnt[15];
int f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		char c=s[i];
		if(c>='0'&&c<='9'){
			cnt[c-'0']=cnt[c-'0']+c;
		}
	}
	for(int i=9;i>=1;i--){
		l=cnt[i].size();
		if(l>0){
			cout<<cnt[i];
			f=1;
		}
	}
	if(!f){
		cout<<0;
		return 0;
	}
	cout<<cnt[0];
	return 0;
}
