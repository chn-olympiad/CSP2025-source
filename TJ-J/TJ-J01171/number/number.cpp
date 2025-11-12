#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int n, cnt=1;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
    cin >> s;
    n = s.size();
    for(int i=0; i<n; i++){
    	if(s[i]-48>=0 && s[i]-48 <=9){
    		a[cnt++] = s[i]-48;
		}
    }
    cnt-=1;
    sort(a+1, a+1+cnt, cmp);
    for(int i=1; i<=cnt; i++) cout << a[i];
    return 0;
}
