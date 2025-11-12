#include<bits/stdc++.h>
using namespace std;
int n, q, ans = 0;

struct node{
	string s1, s2;
	int t1, t2;
	int len;
};

node a[200005], b[200005];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int B = 1;
	cin >> n >> q;
	for (int i =1 ; i <=n; i++){
		cin >> a[i].s1 >> a[i].s2;
		if (a[i].s1[0] != ('a'||'b')|| a[i].s2[0]!=('a'||'b')) B = 0;
	}
	for (int i = 1; i <= q; i++){
		cin >> b[i].s1 >> b[i].s2;
		if (b[i].s1[0] != ('a'||'b') || b[i].s2[0]!=('a'||'b')) B = 0;
	}
	
	if (B){
		for (int i=1 ; i <= n ; i++){
			a[i].t1 = a[i].s1.find('b');
			a[i].t2 = a[i].s2.find('b');
			a[i].len = a[i].s1.length();
		}
		for (int i=1 ; i <= q ; i++){
			b[i].t1 = b[i].s1.find('b');
			b[i].t2 = b[i].s2.find('b');
			b[i].len = b[i].s1.length();
			for (int j=1; j <= n; j++)
				if (b[i].t1 - b[i].t2 == a[j].t1 - a[j].t2 && b[i].t1 >= a[j].t1 && b[i].len - b[i].t1 >= a[j].len - a[j].t1){
					ans += 1;
				}
			cout << ans << endl;
		}
	}
	else {
		for(int i =1; i <= q; i++){
			cout << "0" << endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
