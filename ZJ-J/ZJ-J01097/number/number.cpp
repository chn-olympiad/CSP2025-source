#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	int idx=0;
	char ans[1000005];
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0')ans[idx++]=s[i];
	}
	sort(ans,ans+idx,cmp);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
