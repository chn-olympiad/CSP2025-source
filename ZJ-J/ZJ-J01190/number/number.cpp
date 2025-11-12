#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005],o=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			num[o]=int(s[i]-'0');
			o++;
		}
	}
	sort(num+1,num+o);
	for(int i=o-1;i>=1;i--)cout<<num[i];
	return 0;
}
