#include<bits/stdc++.h>
using namespace std;
string n;
vector<int> ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int k=0;
	for(int i=0;i<n.size();i++){
		if(n[i]=='0' || n[i]=='1' || n[i]=='2' || n[i]=='3' || n[i]=='4' || n[i]=='5' || n[i]=='6' || n[i]=='7' || n[i]=='8' || n[i]=='9') {
			ans.push_back(n[i]-'0');
			if(n[i]!='0') k=1;
		}
		
	}
	if(k==0){
		cout<<0;
		return 0;
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i];
	}
	return 0;
}
