#include<bits/stdc++.h>
using namespace std;
char a[1000005];
bool cmp(int a,int b){
	return a >= b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;      
	cin >> s;
	int len = s.size();
	for(int i=0;i<=len;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[i] += s[i];
		}
	}
	for(int i=0;i<=len;i++){
		a[i] = (int)a[i];
	}
	sort(a,a+len,cmp);
	for(int i=0;i<=len;i++){
		cout << a[i];
	}
	return 0;
}

