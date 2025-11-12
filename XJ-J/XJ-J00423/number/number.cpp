#include<bits/stdc++.h>
using namespace std;
int number[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	freopen("number");
//	freoin("number.in",in);
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){number[ans]=s[i]-'0';ans++; }
	}
	sort(number,number+ans,cmp);
	for(int i=0;i<ans;i++){
		cout<<number[i];
	}
	return 0;
}
