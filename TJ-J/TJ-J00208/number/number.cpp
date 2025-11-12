#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000],k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<10){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(int i=0;i<k;i++){
		cout<<a[i];
	}
	return 0;
}
