#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s;
long long num[1000005],cd,ans;
bool cmp(long long n1,long long n2){
	return n1>n2;
}
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	cd=s.length();
	for(int i=0;i<cd;i++){
		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
			num[i]=s[i]-'0';
			ans++;
		}
	}
	sort(num,num+cd+1,cmp);
	for(int i=0;i<ans;i++){
		cout<<num[i];
	}
	return 0;
}

