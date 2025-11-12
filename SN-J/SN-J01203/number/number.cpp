#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000005],num=0,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='1'){
			num++;
			ans[num]=1;
		}else if(s[i]=='2'){
			num++;
			ans[num]=2;
		}else if(s[i]=='3'){
			num++;
			ans[num]=3;
		}else if(s[i]=='4'){
			num++;
			ans[num]=4;
		}else if(s[i]=='5'){
			num++;
			ans[num]=5;
		}else if(s[i]=='6'){
			num++;
			ans[num]=6;
		}else if(s[i]=='7'){
			num++;
			ans[num]=7;
		}else if(s[i]=='8'){
			num++;
			ans[num]=8;
		}else if(s[i]=='9'){
			num++;
			ans[num]=9;
		}else if(s[i]=='0'){
			num++;
			ans[num]=0;
		}
	}
	sort(ans+1,ans+num+1);
	for(int i=1;i<=num;i++){
		int k=1;
		if(ans==0){
			break;
		}
		for(int j=0;j<i-1;j++){
			k*=10;
		}
		a=a+ans[i]*k;
	}
	cout<<a;
	return 0;
}
