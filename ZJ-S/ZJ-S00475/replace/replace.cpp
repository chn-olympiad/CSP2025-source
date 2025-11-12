/*
if u see this
it means that i will afo
lets play a game
play nm play再不写暴力就没时间了
我要上迷惑行为大赏 uid 869164 
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

string s[N][2];

map<string, string> mp;
map<int, bool> v;
int n, q;

namespace subtask1{
	signed main(){
		while(q--){
			int cnt = 0;
			string t1, t2;cin>>t1>>t2;
			int k = t1.size();
			if(t1.size() != t2.size()){
				cout<<0<<endl;continue;
			}
			for(int j = 1; j <= k; j++){
				if(!v[j])continue;
				for(int i = 0; i+j-1 < k; i++){
					string pl = t1.substr(0, i);
					string p = t1.substr(i, j);
					string pr = t1.substr(i+j, k);
					
					string ql = t2.substr(0, i);
					string q = t2.substr(i, j);
					string qr = t2.substr(i+j, k);
//					cout<<mp[p]<<" "<<q<<endl;
					if(mp[p] == q && pl == ql && pr == qr)cnt++;
				}
			}
			cout<<cnt<<endl;
		}
	}
}

namespace subtask2{
	int hv[N][2];
	vector<int> hp1[N], hp2[N];
	
	int main(){
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < s[i][0].size(); j++){
				if(s[i][0][j] == 'b')hv[i][0] = j;
				if(s[i][1][j] == 'b')hv[i][1] = j;
			}
			if(hv[i][0] > hv[i][1])hp1[hv[i][0] - hv[i][1]].push_back(i);
			else hp2[hv[i][1] - hv[i][0]].push_back(i);
		}
		
		while(q--){
			string t1, t2;cin>>t1>>t2;
			int k = t1.size();
			if(t1.size() != t2.size()){
				cout<<0<<endl;continue;
			}
			int l1, l2;
			for(int i = 0; i < k; i++){
				if(t1[i] == 'b')l1 = i;
				if(t2[i] == 'b')l2 = i;
			}
			int cnt = 0;
			if(l1 > l2){
				int lt = l1 - l2;
				for(auto l : hp1[lt]){
					int sl = s[l][0].size();
					if((k-l1+1 >= sl-hv[l][0]+1 && l1 >= hv[l][0]) && (k-l2+1 >= sl-hv[l][1]+1 && l2 >= hv[l][1]))cnt++;
				}
			}else{
				int lt = l2 - l1;
				for(auto l : hp2[lt]){
					int sl = s[l][0].size();
					if((k-l1+1 >= sl-hv[l][0]+1 && l1 >= hv[l][0]) && (k-l2+1 >= sl-hv[l][1]+1 && l2 >= hv[l][1]))cnt++;
				}
			}
			cout<<cnt<<endl;
		}
	}
}

int main(){
//	freopen("replace.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
//  你被骗了
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i = 1; i <= n; i++)cin>>s[i][0]>>s[i][1], mp[s[i][0]] = s[i][1], v[s[i][0].size()] = 1;
	int fg = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < s[i][0].size(); j++){
			if(!((s[i][0][j] == 'a' || s[i][0][j] == 'b') && (s[i][1][j] == 'a' || s[i][1][j] == 'b'))){
				fg = 1;break;
			}
		}
	}
	if(!fg)subtask2 :: main();
	else subtask1 :: main();
	return 0;	
}
