#include <bits/stdc++.h>
using namespace std;

struct sorter{
	int id;
	int d;
	int f;
};
typedef struct sorter st;

struct state{
	int d;
	int f;
};
typedef struct state sa;

bool cmp(st a, st b){
	if(a.f < b.f) return false;
	if(a.f == b.f && a.d > b.d) return false;
	return true;
}

bool stc(sa a, sa b){
	if(a.f < b.f) return false;
	if(a.f == b.f && a.d > b.d) return false;
	return true;
}

int main(void){
	fstream fin("club.in", ios_base::in);
	fstream fout("club.out", ios_base::out);
	
	unsigned long long int t;
	fin >> t;
	
	while(t--){
		int n;
		fin >> n;
		vector<st> ast;
		vector< vector<sa> > stt;
		
		for(int i=0;i<n;i++){
			int s1, s2, s3;
			fin >> s1 >> s2 >> s3;
			ast.push_back({i, 1, s1});
			ast.push_back({i, 2, s2});
			ast.push_back({i, 3, s3});
			vector<sa> ds;
			ds.push_back({1, s1});
			ds.push_back({2, s2});
			ds.push_back({3, s3});
			sort(ds.begin(), ds.end(), stc);
			stt.push_back(ds);
		}
		
		sort(ast.begin(), ast.end(), cmp);
		
		vector<sa> stsa(n, {0, 0});
		vector<int> dep(4, 0);
		for(int i=0;i<ast.size();i++){
			if(stsa[ast[i].id].d == 0){
				if(dep[ast[i].d] < n / 2){
					stsa[ast[i].id].d = ast[i].d;
					stsa[ast[i].id].f = ast[i].f;
					dep[ast[i].d]++;
				}
				else{
					int o1;
					for(o1=0;o1<3;o1++){
						if(stt[ast[i].id][o1].d == ast[i].d) {
							o1++;
							break;
						}
					}
					if(o1 == 3){
						for(o1=0;o1<3;o1++){
							if(dep[stt[ast[i].id][o1].d] < n / 2) {
								break;
							}
						}
						stsa[ast[i].id].d = stt[ast[i].id][o1].d;
						stsa[ast[i].id].f = stt[ast[i].id][o1].f;
					}
					else{
						int k = i;
						for(int j=i-1;j>=0;j--){
							if(ast[j].d == ast[i].d && stsa[ast[j].id].d == ast[j].d){
								int o;
								for(o=0;o<3;o++){
									if(stt[ast[j].id][o].d == ast[j].d) {
										o++;
										break;
									}
								}
								if(o < 3){
									if(stt[ast[j].id][o].f + ast[i].f >= stsa[ast[j].id].f + stt[ast[i].id][o1].f){
								 		stsa[ast[j].id].d = stt[ast[j].id][o].d;
										stsa[ast[j].id].f = stt[ast[j].id][o].f;
										stsa[ast[i].id].d = ast[i].d;
										stsa[ast[i].id].f = ast[i].f;
										i = j;
									}
								}
							}
						}
						i = k;
					}
				}
			}
		}
		
		int ans = 0;
		for(int i=0;i<n;i++)
			ans += stsa[i].f;
		
		fout << ans << endl;
	}
	return 0;
}
