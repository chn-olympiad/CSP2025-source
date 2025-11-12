#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],num,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>'0'and s[i]<='9'){
			num++;
			a[num]=s[i]-'0';
			cnt++;
		}
		if(s[i]=='0'){
			num++;
			a[num]=s[i]-'0';
		}
	}
	sort(a+1,a+num+1,cmp);
	if(cnt==0){
		cout<<0;
	}
	else{
	for(int i=1;i<=num;i++){
		cout<<a[i];
	}
}
}


