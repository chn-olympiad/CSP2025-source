#include <bits/stdc++.h>

 using namespace std;
 int num[1000005];
 string s;
 bool cmp(int a,int b){
	 return a>b;

 }
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=1;
	for(int i=0;i<s.size();i++){
		
		if(s[i]>='0'&&s[i]<='9'){
			num[a]=s[i]-'0';
			a++;
	}}
	sort(num,num+a,cmp);
	for(int i=0;i<a-1;i++){
		cout<<num[i];
	}
	return 0;
}
