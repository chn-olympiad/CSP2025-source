#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005]={};
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size(),j=0;
	for(int i=0;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]+=s[i];
			j++;
		}
	}
	sort(a,a+j,cmp);
	cout<<a;
}
