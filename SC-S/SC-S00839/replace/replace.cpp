#include<bits/stdc++.h>
using namespace std;

int n, q;

map<string, string> mp; 

string get(string a, int ii, int jj, string mm){
	string x;
	for(int i = 0;i < ii;i ++){
		x += a[i];
	}
	x += mm;
	for(int i = jj + 1;i < (int)a.size();i ++){
		x += a[i];
	}
	return x;
}

int ans = 0;

void work(string a, string b){
	ans = 0;
	for(int i = 0;i <= (int)a.size();i ++){
		string c;
		for(int j = i;j <= (int)a.size();j ++){
			c += a[j];
			if(mp[c] != ""){
				
				string d = get(a, i, j, mp[c]);
				if(d == b)ans ++;
			}
		}
	}
	return ;
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i ++){
		string a, b;
		cin >> a >> b;
		mp[a] = b;
	} 
	for(int i = 1;i <= q;i ++){
		string a, b;
		cin >> a >> b;
		work(a, b);
		printf("%d\n", ans);
	}
	
	
	
	return 0;
}