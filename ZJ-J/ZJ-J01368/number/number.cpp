#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005];
int res=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			res++;
			num[res]=s[i]-'0';
		}
	}
	sort(num+1,num+res+1,cmp);
	for(int i=1;i<=res;i++){
		cout<<num[i];
	}
	return 0;
}