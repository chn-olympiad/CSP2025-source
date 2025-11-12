#include<bits/stdc++.h>
using namespace std;
int a[1000001],num;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num++;
			a[num]=s[i]-'0';
		}
	}
	sort(a+1,a+1+num,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=num;i++){
		cout<<a[i];
	}
	return 0;
}

