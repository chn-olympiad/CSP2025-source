#include<bits/stdc++.h>
using namespace std;
string ch;
int s[1000000];
int cnt=0;
bool cmp(int a,int b){
	return a>b;
}//跟去年一模一样？？？？ 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ch;
	for(int i=0;i<ch.size();i++){
		if(!(ch[i]>='A'&&ch[i]<='z')){
			cnt++;
			s[cnt]=ch[i]-'0';
		}
	}
	sort(s+1,s+1+cnt,cmp);
	for(int j=1;j<=cnt;j++){
		cout<<s[j];
	}
	return 0;
} 
