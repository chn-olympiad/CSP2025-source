#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
long long a[N],cnt;
bool com(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
			cnt++;
			a[cnt] = s[i] - '0';
		}
	}
	sort(a + 1,a + 1 + cnt,com);
	for(int i = 1;i <= cnt;i++) cout << a[i];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
