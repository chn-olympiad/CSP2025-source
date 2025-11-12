#include<bits/stdc++.h>

using namespace std;

string s;
const int N = 1e6+10;
int a[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int cnt = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			cnt++;
			a[cnt] = int(s[i] - '0');
		}
	}
	sort(a,a+cnt+1);
	for(int i = cnt;i >= 1;i--){
		cout << a[i];
	}
	
	return 0;
}
