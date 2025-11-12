#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000006];
int cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	bool flag=false;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			num[cnt]=s[i]-'0';
			if(num[cnt]!=0)flag=true;
		}
	}sort(num+1,num+cnt+1,cmp);
	if(flag==false){
		cout<<0<<endl;
	}else {
		for(int i=1;i<=cnt;i++){
			cout<<num[i];
		}
	}
	return 0;
}