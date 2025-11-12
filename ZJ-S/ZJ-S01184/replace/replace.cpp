#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
string s1[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s1[i][0];
		cin >> s1[i][1];
	}
	for(int i = 1; i <= q; i++){
		long long ans1 = 0;
		string que, ans;
		cin >> que >> ans;
		for(int j = 0; j < que.size(); j++){
			for(int h = 1; h <= n; h++){
				if(j+s1[h][0].size() > que.size()){
					continue;
				}
				string sum = que;
				bool y = 0;
				for(int z = 0; z < s1[h][0].size(); z++){
					if(s1[h][0][z] != que[j+z]){
						y = 1;
						break;
					}
					else{
						sum[j+z] = s1[h][1][z];
					}
				}
				if(y){
					continue;
				}
				if(sum == ans){
					ans1++;
				}
			}
		}
		cout << ans1 << "\n"; 
	}
	return 0;
}
