// 这个题大概用的 KMP 吧
// 16:44 更新状态：不会放弃。
// 17:17 更新状态：不会，放弃。

#include <bits/stdc++.h>

#define ll long long

using namespace std;

typedef pair<string, string> dict_item;

int n, q;
vector<dict_item> dict0, to_query;
vector<int> query_result;

int user_input(){
	cin >> n >> q;
	dict0.resize(n);
	to_query.resize(q);
	query_result.resize(q);
	for(int i = 0; i < n; i++){
//		dict_item tmp;
//		cin >> tmp.first >> tmp.second;
		cin >> dict0[i].first >> dict0[i].second;
	}
	for(int j = 0; j < q; j++){
		cin >> to_query[j].first >> to_query[j].second;
	}
	return 0;
}


int query_m(dict_item from_to){
	// 返回有多少种替换方式
	// 使用了全局变量 dict0
	int tihuan = 0;
//	/*
	for(auto it: dict0){
		bool have_panding = false;
		int current_tihuan = 0;
		for(int i = 0; i < from_to.first.length(); i++){
			if(have_panding or current_tihuan != 0){
				//printf("HP - %d\n", i);
				if(from_to.first[i] != from_to.second[i]){
					//printf("判定 %d 次后断触 at %d\n", current_tihuan, i);
					current_tihuan = 0;
					break;
				}
			} else {
				int jb = 0;
				if(from_to.first[i] == from_to.second[i]) continue;
				while(from_to.first[i+jb] == it.first[jb] and from_to.second[i+jb] == it.second[jb]){
					// 探路性判定成功，进入整体判定
					//printf("探路性判定成功，i=%d, jb=%d\n", i, jb);
					jb++;
					// 特判：从此位点至结尾完全相等
					if(jb == it.first.length() or jb == from_to.first.length()){
						// current_tihuan++;
						// 此处不能++，因为后续还会有一次++
						//printf("退出判定 at i=%d, jb=%d\n", i, jb);
						break;
					}
				}
				i += jb;
				if(jb == 0 or jb < it.first.length()){
					//printf("miss/断触 at jb=%d, length=%d\n", jb, it.first.length());
					current_tihuan = 0;
					break;
				}
				if(jb == it.first.length()){
//					printf("判定成功，jb=%d, it: ", jb);
					//printf("判定成功，jb=%d, ", jb);
					//cout << "from_to: " << from_to.first << " -> " << from_to.second;
					//cout << ", it: " << it.first << " -> " << it.second << endl;
					have_panding = true;
					current_tihuan++;
				} else {
					//cout << "CNMM!!!!!" << endl;
				}
			}
		}
		tihuan += current_tihuan;
	}
//	*/
	return tihuan;
}


int main(void){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
//	int h = 122222222;
//	while(h--){
//		printf("FFFFFFFFFFFFFFF");
//	}
	///////////////////////////////////////////////
	user_input();
	int ch = 0;
	for(auto it: to_query){
		// query_result.push_back(query_m(it));
		// query_result[i] = query_m(it);
		cout << query_m(it) << endl;
		ch++;
	}
	///////////////////////////////////////////////
	fclose(stdin);
	fclose(stdout);
	// cout << system("fc replace.ans replace.out") << endl;
	return 0;
}

