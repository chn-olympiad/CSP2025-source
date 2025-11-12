#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;

struct String{
	string s1;
	string s2;
}st[MAXN];
int n,q;
//set <string> st;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> st[i].s1 >> st[i].s2;
	}
	for(int i = 1;i <= q;i++){
		string t1,t2;
		cin >> t1 >> t2;
		int ans = 0;
		for(int j = 1;j <= n;j++){
			if(t1.find(st[j].s1) != -1 && t2.find(st[j].s2) != -1 && t1.find(st[j].s1) == t2.find(st[j].s2)){
//				cout << st[j].s1 << " " << st[j].s2 << endl;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
