#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],b=0;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[i]=int(s[i]-48);
			b++;
		} 
	}
	sort(a,a+b+1,cmp);
	for(int i=0;i<b;i++){
		cout<<a[i];
	}
	return 0;
} 
