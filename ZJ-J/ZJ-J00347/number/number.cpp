#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n = s.size();
	int tot = 0;
	for(int i=0;i<n;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++tot] = int(s[i] - '0');
		}
	}
	sort(a+1,a+1+tot,cmp);
	for(int i=1;i<=tot;i++)
		cout << a[i];
	return 0;
}
// CSP-S RP++;