#include<bits/stdc++.h>
using namespace std;
string a;
long long s[100086];
long long j=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			s[j]=a[i]-'0';
			j++;
		}
	}
	sort(s+1,s+a.size()+1,cmp);
	for(int i=1;i<j;i++){
		cout<<s[i];
	}
	return 0;
}
