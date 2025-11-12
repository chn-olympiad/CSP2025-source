#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	FASTIO;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	s=" "+s;
	vector<char> ve;
	for(int i=1;i<=len;i++){
		if(s[i]<='9'&&s[i]>='0')ve.push_back(s[i]);
	}
	sort(ve.begin(),ve.end(),cmp);
	for(int i=0;i<ve.size();i++)cout<<ve[i];
	return 0;
}
