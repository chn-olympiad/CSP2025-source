#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(isdigit(s[i])){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
		cout<<v[i];
	}
	return 0;
}
//freopen
//8:40 is guo le quan bu yang li
//jin nian de ti hao shui a 
//yi yan si dao dou hui
