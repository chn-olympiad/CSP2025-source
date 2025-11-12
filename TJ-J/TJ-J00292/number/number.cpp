#include<bits/stdc++.h>
using namespace std;
bool cmd(int a,int b){
    return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
   	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	vector<int> v;
	for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            v.push_back(s[i]-'0');
        }
	}
	sort(v.begin(),v.end(),cmd);
	string a;
	for(int i=0;i<v.size();i++){
        a+=(v[i]+'0');
	}
	cout<<a;
	return 0;
}
