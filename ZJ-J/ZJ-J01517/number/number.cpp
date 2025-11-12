#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],n;
bool com(int a,int b){
	return a>b;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n+1]=s[i]-'0';
			n++;
		}
	}
	sort(a+1,a+n+1,com);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}
