#include <bits/stdc++.h>
using namespace std;

int tr[N][30];

void insert(string a){
	for(char i : a){
		int k = i - 'a';
		if(!tr[u][k]) tr[u][k] = ++idx;
		u = tr[u][k];
	}
	cnt[u]++;
	return ;
}
void query(int u){
	fail[1] = 1;
	for(int i = 1; i <= idx; i++){
		for(int k = 0; k < 26; k++){
			if(tr[i][k]){
				int u = fail[i];
				while(!tr[u][k]){
					u = fail[u];
					if(u == 1) break;
				}
				if(!tr[u][v]) fail[tr[i][k]] = 1;
				else fail[tr[i][k]] = tr[u][k];
			}
		}
	}
	return ;
}

signed main(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string u, v, a;
		cin >> u >> v;
		for(int j = 0; j < u.size(); j++){
			a += u[j];
			a += v[j];
		}
		insert(a);
	}

	for(int i = 1; i <= idx; i++){
		cout << i << " " << fail[i] << "\n";
	}
	// for(int i = 1; i <= q; i++){
	// 	cin >> s >> t;
	// }
	return 0;
}