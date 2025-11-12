#include<bits/stdc++.h>
using namespace std;
int a[10100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio;cin.tie(0);cout.tie(0);
	string s;
	cin >> s;
	int q=s.size(),e=0;
	for(int i=0;i<q;i++){
		int w=0;
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=int(s[i])-'0';
			w++;
		}
		if(w==0) e++;
	}
	sort(a,a+q);
	for(int i=q-1;i>e-1;i--){
		cout << a[i];
	}
	return 0;
}
