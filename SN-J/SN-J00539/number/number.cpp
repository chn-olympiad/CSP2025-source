#include <bits/stdc++.h>

using namespace std;
string l;
char f[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> l;
	int m=1;
	for(int i=0;i<l.length();i++){
		if(l[i]>='0'&&l[i]<='9'){
			f[m]=l[i];
			m++;
		}
	}
	sort(f+1,f+m);
	for(int i=m-1;i>=1;i--){
		cout<<f[i];
	}
	return 0;
}
