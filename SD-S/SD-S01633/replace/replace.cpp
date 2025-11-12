#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
map<string,int>id;
vector<string>e[N];
int n,Q,cnt,ans;
string get_str(string s,int l,int r){
	string res = "";
	for(int i = l;i <= r;i ++){
		res += s[i];
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> Q;
	
	for(int i = 1;i <= n;i ++){
		string s1,s2;
		cin >> s1 >> s2;
		if(!id[s2]){
			id[s2] = ++ cnt;
			e[id[s2]].push_back(s1);
		}
	}
	
	while(Q --){
		ans = 0;
		string S1,S2;
		cin >> S1 >> S2;
		int l,r;
		int len = S1.size();
		for(int i = 0;i < len;i ++){
			if(S1[i] != S2[i]){
				l = i;
				break;
			}
		} 
		
		for(int i = len - 1;i >= 0;i --){
			if(S1[i] != S2[i]){
				r = i;
				break;
			}
		} 
		
		for(int i = 0;i <= l;i ++){
			for(int j = r;j < len;j ++){
				string now = get_str(S2,i,j);
				string to = get_str(S1,i,j);
				if(!id[now])continue;
				for(int k = 0;k < e[id[now]].size();k ++){
					if(e[id[now]][k] == to){
						ans ++;
					}
				}
			}
		}
		cout << ans << "\n";
		
	}
	
	
	
	
	
	
	
	
	return 0;
} 
