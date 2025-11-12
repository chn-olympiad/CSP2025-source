#include<bits/stdc++.h>
using namespace std;
int a[1000000];
bool cmp(int a,int b){
	return a>b;
}
int x;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	int x=0;
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>'0'&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a,a+x,cmp);
	for(int i=0;i<x;i++){
        cout << a[i];
	}
	return 0;
}
