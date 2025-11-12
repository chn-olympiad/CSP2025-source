#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N];
string s;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	int numl = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i] <= '9' && s[i]>= '0'){
			a[numl ++] = s[i] - '0';
		}
	}
	sort(a,a+numl,cmp);
	for(int i = 0;i < numl;i++){
		cout << a[i];
	}
	return 0;
} 
