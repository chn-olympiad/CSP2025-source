#include<bits/stdc++.h> 
using namespace std;
string s;
int a[1000001],n;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i<s.length();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[i]=s[i]-'0';n++;
		}
	}
	sort(a,a+s.length()+1,cmp);
	for(int i = 0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
