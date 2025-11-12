#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt[10]={};
	cin>>s;
	for(int i=0,en=s.size();i<en;i++)
		if(s[i]>='0'&&s[i]<='9')
			cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(cnt[i]--)
			printf("%d",i);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
