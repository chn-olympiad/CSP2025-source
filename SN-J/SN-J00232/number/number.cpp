#include<bits/stdc++.h>
using namespace std;
string a;
int s[1000001],j=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			s[j++]=a[i]-'0';
		}
	}
	sort(s,s+j,cmp);
	for(int i=0;i<j;i++) cout<<s[i];
	return 0;
}
