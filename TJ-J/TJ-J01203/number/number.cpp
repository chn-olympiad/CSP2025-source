#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int b[N]= {};
bool cmd(int a,int b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length(),k=0;
	for(int i=0; i<n; i++) {
		if('0'<=s[i]&&s[i]<='9') b[k]=s[i]-'0',k++;
	}
	sort(b+0,b+k,cmd);
	for(int i=0; i<k; i++) {
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
