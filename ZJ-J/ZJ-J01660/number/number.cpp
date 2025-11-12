#include<bits/stdc++.h>
using namespace std;
string s;
long long tong[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')tong[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(tong[i]>0)printf("%d",i),tong[i]--;
	}
	return 0;
}
