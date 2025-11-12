#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int si;
bool ord(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			si++;
			a[si]=s[i]-'0';
		}
	}
	sort(a+1,a+si+1,ord);
	for(int i=1;i<=si;i++){
		cout<<a[i];
	}
	return 0;
}
