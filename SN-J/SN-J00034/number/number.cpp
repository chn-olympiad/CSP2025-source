#include<bits/stdc++.h>
using namespace std;
long long a,c[100010],d,e[100010];
string s;
char b;
int main(){
	freopen("number.in","r", stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(long long i=0;i<s.size();i++){
		if(isdigit(s[i])) {
			b=s[i];
			d=b;
			c[a]=d-48;
			a++;	
		}
	}
	sort(c,c+a);
	for(long long i=a-1;i>=0;i--){
		cout << c[i] ;
	}
	return 0;
}
