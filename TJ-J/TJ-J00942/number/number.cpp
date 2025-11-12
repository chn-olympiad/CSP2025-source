#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ans[100010]={0};
	int j=0;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			j++;
			ans[j]=s[i]-'0';
		}
	}
	//cout<<ans;
	sort(ans+1,ans+1+j);
	for(int i=j;i>=1;i--){
		cout<<ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

