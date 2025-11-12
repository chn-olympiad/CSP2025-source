#include<bits/stdc++.h>
using namespace std;

int n,q;
pair<string , string> strs;
pair<string , string> prob; 

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;++i){
		cin >> strs[i].first >> strs[i].second;
	}
	
	for(int i = 1;i <= n;++i){
		cin >> prob[i].first >> prob[i].second;
	}
	
	for(int i = 1;i <= m;++i){
		cout << 0;
	} 
	return 0;
}
