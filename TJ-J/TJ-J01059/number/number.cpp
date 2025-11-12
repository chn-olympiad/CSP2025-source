#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	vector<int> ans(0);
	cin>>n;
	for(int i=0;i<n.length();i++){
		if(n[i]>='0' && n[i]<='9'){
			ans.push_back(n[i]-'0');
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
