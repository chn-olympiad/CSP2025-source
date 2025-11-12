#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],num=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[num]=s[i]-'0';
			num++;
		}
	}
	sort(a+1,a+num+1);
	for(int i=num;i>1;i--){
		cout<<a[i];
	}
	return 0;
}
