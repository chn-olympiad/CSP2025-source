#include<bits/stdc++.h>
using namespace std;
string s;
int num[1001110];
int t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9') num[++t]=s[i]-'0';
	}
	sort(num+1,num+1+t);
	for(int i=t;i>=1;i--){
		cout<<num[i];
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
