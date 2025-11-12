//SN-J00533 lihaoze xianfulunzhongxue
#include<bits/stdc++.h>
using namespace std;
bool cmp(int m,int n){
	return m>n;
}

int main(){
	freopen("number3.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char a[100005];
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			a[i]=s[i];
		}
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<s.size();i++){
		cout<<a[i];
		
	}
	return 0;
}
