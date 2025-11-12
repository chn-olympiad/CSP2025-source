#include <bits/stdc++.h>
using namespace std;
char a[1000010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char x;
	int l = 0;
	while(cin >> x){
		if('0'<=x&&x<='9'){
			l++;
			a[l] = x;
		}
	}
	sort(a+1,a+l+1);
	for(int i = l;i>0;i--){
		cout << a[i];
	}
	return 0;
}
