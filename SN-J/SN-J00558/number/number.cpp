#include <bits/stdc++.h>
using namespace std;
string s,a;
int t = 0;
int maxn = -21000000;
int c = 1;
long long siz;
string b;
int m = 21000000;
int shu[10000001];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	siz = s.size();
	for(int i = 0;i < siz;i++){
		if(s[i] == '1') {
			t++;
			a[t] = s[i];
		}else if(s[i] == '2'){
			t++;
			a[t] = s[i];	
		}else if(s[i] == '3'){
			t++;
			a[t] = s[i];	
		}else if(s[i] == '4'){
			t++;
			a[t] = s[i];	
		}else if(s[i] == '5'){
			t++;
			a[t] = s[i];	
		}else if(s[i] == '6'){
			t++;
			a[t] = s[i];	
		}else if(s[i] == '7'){
			t++;
			a[t] = s[i];	
		}else if(s[i] == '8'){
			t++;
			a[t] = s[i];	
		}else if(s[i] == '9'){
			t++;
			a[t] = s[i];	
		}else if(s[i] == '0'){
			t++;
			a[t] = s[i];	
		}
	}
	for(int i = 1;i <= t;i++){
		shu[i] = a[i] + '0';
	}
	sort(shu + 1,shu + t + 1,cmp);
	for(int i = 1;i <= t;i++){
		a[i] = shu[i] - '0';
	}
	for(int i = 1;i <= t;i++){
		cout << a[i];
	}
	return 0;
}
