#include<bits/stdc++.h>
#define lint long long
using namespace std;
int n,qq,ans;
pair<string,string> s[200002];
string t1,t2;
map<string,bool> mp;
string tostr(int r){
	string rg = "";
	while(r > 0){
		rg += r % 10 + '0';
		r /= 10;
	}
	return rg;
}
void bfs(string t){
	queue<pair<string,string> > q;
	q.push({t,""});
	while(!q.empty()){
		mp[""] = true;
		pair<string,string> pppp = q.front();
		cout << pppp.first << endl; 
		string x = pppp.first,xxxx = pppp.second;
		if(mp[xxxx] == true){
			q.pop();
			continue;
		}
		if(x == t2){
			break;
		}
		q.pop();
		bool b = false;
		for(int i = 1;i <= n;i++){
			string xx = x;
			while(xx.find(s[i].first) != string::npos){
				int p = xx.find(s[i].first);
				xx.erase(p,s[i].first.length());
				xx.insert(p,s[i].second);
			}
			if(!mp[xxxx + tostr(i)] && xx != x){
				b = true;
				pppp.first = xx,pppp.second = xxxx + tostr(i);
				if(xx != t2 || !mp[xxxx + tostr(i)]) q.push(pppp);
				mp[xxxx + tostr(i)] = true;
			}
			if(xx == t2){
				ans++;
				b = true;
			}
		}
		if(b) q.push({t,""});
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> qq;
	for(int i = 1;i <= n;i++){
		string pp,ppp;
		cin >> pp >> ppp;
		pair<string,string> ppppppp;
		ppppppp.first = pp;
		ppppppp.second = ppp;
		s[i] = ppppppp;
	}
	while(qq--){
		mp.clear();
		ans = 0;
		cin >> t1 >> t2;
		bfs(t1);
		cout << ans << endl;
	}
	return 0;
}
