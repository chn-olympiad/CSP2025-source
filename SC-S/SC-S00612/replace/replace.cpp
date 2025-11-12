#include <bits/stdc++.h>
using namespace std;
bool find_and_replace(const string& src, const string& dst, const string& replace_scr, const string& replace_dst){
	if (replace_scr.size()>src.size()||replace_dst.size()>dst.size()) return false;
	if (src==replace_scr&&dst==replace_dst) return true;
	for(size_t i=0;i<src.size()-replace_scr.size();i++){
		if(src[i]==replace_scr[0]&&src.substr(i, replace_scr.size())==replace_scr){
			string tmp = src;
			tmp.replace(tmp.begin()+i, tmp.begin()+i+replace_scr.size(), replace_dst);
			if (tmp==dst) return true;
		}
	}
	return false;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n,q;
	scanf("%d %d", &n, &q);
	vector<pair<string, string>> a;
	vector<pair<string, string>> _q;
	for(int i=0;i<n;i++){
		pair<string, string> tmp("", "");
		cin>>tmp.first>>tmp.second;
		a.push_back(tmp);
	}
	for(int i=0;i<q;i++){
		pair<string, string> tmp("", "");
		cin>>tmp.first>>tmp.second;
		_q.push_back(tmp);
	}
	
	for(pair<string, string> i : _q){
		int cnt = 0;
		for(pair<string, string> j : a){
			if (find_and_replace(i.first, i.second, j.first, j.second)) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}