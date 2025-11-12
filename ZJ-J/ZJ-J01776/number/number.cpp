#include<bits/stdc++.h>
using namespace std;
string st;
int a[1000050], k;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> st;
	int sz=st.size();
	for(int i=0;i<sz;i++){
		if(st[i]>='0'&&st[i]<='9'){
			k++;
			a[k]=st[i]-'0';
		}
	}
	sort(a+1, a+k+1);
	for(int i=k;i>=1;i--){
		cout << a[i];
	}
}