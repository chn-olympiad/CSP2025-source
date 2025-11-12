#include<bits/stdc++.h>
using namespace std;
string s,ss;
vector<int>vec;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			vec.push_back(s[i]-'0');
		}
	}sort(vec.begin(),vec.end());
	for(int i=vec.size()-1;i>=0;i--){
		cout<<vec[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
