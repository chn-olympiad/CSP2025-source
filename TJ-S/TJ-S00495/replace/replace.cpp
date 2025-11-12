#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n, T;
vector<char> fromstr0;
vector<char> tostr0;
vector<bool> diff0;
int diffstart0;
int diffend0;
vector<vector<char> > fromstrs(0);
vector<vector<char> > tostrs(0);
vector<vector<bool> > diffs(0);
vector<int> diffstarts(0);
vector<int> diffends(0);

bool Handle(vector<char> &fromstr, vector<char> &tostr, vector<bool> &diff, int &diffstart, int &diffend){
	string s[2];
	cin >> s[0] >> s[1];
	if(s[0].length() != s[1].length()){
		return false;
	}
	for(int i = 0; i < s[0].length(); i ++){
		fromstr.push_back(s[0][i]);
	}
	for(int i = 0; i < s[1].length(); i ++){
		tostr.push_back(s[1][i]);
	}
	int p = 0;
	while(fromstr[p] == tostr[p] && p < fromstr.size()){
		p ++;
	}
	diffstart = p;
	int emptycnt = 0;
	diff = vector<bool>(0);
	for(; p < fromstr.size(); p ++){
		if(fromstr[p] == tostr[p]){
			emptycnt ++;
		}else{
			while(emptycnt){
				emptycnt --;
				diff.push_back(false);
			}
			diff.push_back(true);
		}
	}
	diffend = (fromstr.size()-emptycnt-1);
	return true;
}

int Init(){
	cin >> n >> T;
	for(int i = 0; i < n; i ++){
		fromstrs.push_back(vector<char>(0));
		tostrs.push_back(vector<char>(0));
		diffs.push_back(vector<bool>(0));
		diffstarts.push_back(0);
		diffends.push_back(0);
		Handle(fromstrs[i], tostrs[i], diffs[i], diffstarts[i], diffends[i]);
	}
}

int Solve(){
	fromstr0 = vector<char>(0);
	tostr0 = vector<char>(0);
	diff0 = vector<bool>(0);
	diffstart0 = 0;
	diffend0 = 0;
	if(!Handle(fromstr0, tostr0, diff0, diffstart0, diffend0)){
		return 0;
	}
	int cnt = 0;
	for(int i = 0; i < fromstrs.size(); i ++){
		if(diffs[i].size() != diff0.size()) continue;
		if(fromstrs[i].size() > fromstr0.size()) continue;
		bool flag = false;
		for(int j = 0; j < diffs[i].size(); j ++){
			if(diffs[i][j] != diff0[j]){
				flag = true; break;
			}
		}
		if(flag) continue;
		int offset = diffstart0 - diffstarts[i];
		if(offset < 0 || offset + fromstrs[i].size() > fromstr0.size()) continue;
		flag = false;
		for(int j = 0; j < fromstrs[i].size(); j ++){
			if(fromstrs[i][j] != fromstr0[j+offset] || tostrs[i][j] != tostr0[j+offset]){
				flag = true; break;
			}
		}
		if(flag) continue;
		cnt ++;
	}
	return cnt;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	Init();
	while(T --){
		printf("%d\n", Solve());
	}
	return 0;
}
