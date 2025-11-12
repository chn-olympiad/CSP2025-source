#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	int c;
	if(b>a){
		c=b;
		b=a;
		a=c;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<char> s;
	vector<int> ans;
	for(int i=0;i<s.size();i++){
		cin>>s[i];
		if(s[i]<='9' && s[i]>='0'){
			ans[i]=s[i];
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i];
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
