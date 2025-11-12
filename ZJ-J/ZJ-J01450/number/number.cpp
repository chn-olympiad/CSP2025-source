#include <bits/stdc++.h>
using namespace std;
//priority_queue<int> q;
int n,f[10],sum=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//1234567890-=`\qwertyuiop[]\asdfghjkl;''zxcvbnm,./
	cin>>s;
	n=s.length();
	for (int i=0;i<n;++i){
		if (s[i]>='0'&&s[i]<='9'){
			//sum++;
			f[s[i]-'0']++;
		}
	}
	for (int i=9;i>=0;--i){
		for (int j=1;j<=f[i];++j){
			cout<<i;
			//printf("%d",i);
		}
	}
	return 0;
}
