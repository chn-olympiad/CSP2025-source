#include <bits/stdc++.h>
using namespace std;
int cut = 1,a[1000010];
string s;
string ans = "";
bool cmp(int a1,int a2){
	return a1 > a2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++){
		if (s[i] <= '9' && s[i] >= '0'){
			a[cut] = int(s[i] - '0');
			cut++;
		}
	}
	sort(a+1,a+cut+1,cmp);
	for (int i = 1; i < cut; i++){
		printf("%d",a[i]);
	}
	return 0;
}
