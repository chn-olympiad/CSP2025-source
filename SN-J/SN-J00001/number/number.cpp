#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000010];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int w=s.length();
	for (int i=0;i<w;i++){
		if(int(s[i])>=48 and int(s[i])<=57){
			a[i]=s[i]-'0';
		}
		else{
			a[i]=-1;
		}
	}
	sort(a,a+w,cmp);
	for (int i=0;i<w;i++){
		if(a[i]!=-1){
			cout<<a[i];
		}
	}
	return 0;
}
