#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int l = s.size();
	int cnt = 0;
	int a[l+1]; 
	for(int i = 0;i < l;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			cnt++;
			a[cnt] = s[i]-'0';
		}else{
			continue;
		}
	}
	sort(a+1,a+cnt+1);
	for(int i = cnt;i >= 1;i--){
		cout << a[i];
	}
	return 0;
}
