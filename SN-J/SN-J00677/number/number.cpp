//DuanChencheng's code
//number:SN-J00677
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
string s;   
int num[1000005],cnt,flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			num[++cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+cnt+1);
	if(num[cnt]==0)cout<<0;
	else
	for(int i=cnt;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}
