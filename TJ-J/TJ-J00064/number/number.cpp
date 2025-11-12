#include<bits/stdc++.h>
using namespace std;
string s;
int len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num[1000005];
	int ind=-1;
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			ind++;
			num[ind]=s[i]-'0';
		}
	}
	sort(num,num+ind+1);
	for(int i=len-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}
