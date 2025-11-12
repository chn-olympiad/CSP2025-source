#include<bits/stdc++.h>
using namespace std;
string s,s1;
vector<long long> v;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]=='0'){
				v.push_back(0);
			}else{
				v.push_back(s[i]-'0');	
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		s1+=v[i]+'0';
	}
	cout<<s1;
	return 0;
}

