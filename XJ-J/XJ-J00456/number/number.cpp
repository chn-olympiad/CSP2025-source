#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int len=s.length();
	int cnt=1;
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[cnt]=int(s[i]-'0');
			cnt++;
		}
	} 
	sort(a+1,a+cnt,cmp);
	for(int i=1;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
} 
