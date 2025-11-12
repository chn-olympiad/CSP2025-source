#include<bits/stdc++.h>
using namespace std;
string str;
int a[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9')a[++cnt]=str[i]-'0';
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;//!
}
