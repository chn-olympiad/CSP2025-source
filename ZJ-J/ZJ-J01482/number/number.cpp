#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

vector<int> res;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	fast;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	string s;
	cin>>s;
	
	for(int i=0;i<s.size();i++){
		char c=s[i];
		if(c>='0'&&c<='9')res.push_back(c-'0');
	}
	sort(res.begin(),res.end(),cmp);
	
	for(int i:res)cout<<i;
	
	
	return 0;
} 

