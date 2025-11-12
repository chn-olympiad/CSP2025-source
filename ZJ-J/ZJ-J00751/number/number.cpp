#include<bits/stdc++.h>
using namespace std;
string s;
vector<char>res;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int Lens=s.size();
	for(int i=0;i<Lens;i++){
		if('0'<=s[i]&&s[i]<='9')res.push_back(s[i]);
	}
	sort(res.begin(),res.end(),cmp);
	for(char i:res)cout<<i;
	return 0;
}