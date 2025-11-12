//商峻熙 SN-J00227 西安市曲江第一中学 
#include <bits/stdc++.h> 
#define ll long long
using namespace std;
const int N = 1e6+10;
string s;
vector<int> a;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i]<'0' || s[i]>'9')continue;
		a.push_back(s[i]-'0');
	}
	sort(a.begin(),a.end(),cmp);
	for(int i = 0;i < a.size();i++){
		printf("%d",a[i]);
	}
	return 0;
}
