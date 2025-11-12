#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> vc;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin >> s;
	for(int i = 0;i<s.size();i++){
		char c = getchar();
		if('0' <= c && c <= '9'){
			vc.push_back(c-'0');
		}
	} 
	sort(vc.begin(),vc.end(),cmp);
	if(vc[0] == 0){
		cout << 0;
		return 0; 
	} 
	for(int i = 0;i<vc.size();i++){
		cout << vc[i];
	}
	return 0; 
}
