#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int q=s[i]-'0';
		a[q]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)
			cout<<i;
	}
	return 0;
}
//先提取数字，
//再用桶统计，
//貌似不需要ASCII码？ 
