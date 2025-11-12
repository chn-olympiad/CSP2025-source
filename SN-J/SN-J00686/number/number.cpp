//SN-J00686  汤佳忆  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
string s;
int a[MAXN],j=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int ss=s[i]-'0';
			a[j]=ss;
			j++;
		}
	}
	sort(a+1,a+1+j,cmp);
	for(int i=1;i<j;i++) cout<<a[i];
	return 0;
}
