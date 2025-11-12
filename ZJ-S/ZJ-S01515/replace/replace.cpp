#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
map<string,string> M;
ll n,q;
ll solve(string s1,string s2){
	ll cnt=0;	
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			for(int j=i;j<s1.size();j++){
				string x=s1.substr(0,i),y=M[s1.substr(i,(j-i+1))],z=s1.substr(j+1);
				if((x+y+z==s2)){
					cnt++;
					//cout<<i<<' '<<j;
				}
			}
		}
	}
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		ll ind=0;
		while(s1[ind]==s2[ind]) ind++;
		s1=s1.substr(ind),s2=s2.substr(ind);
		//cout<<s1<<' '<<s2<<'\n';
		M[s1]=s2;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		cout<<solve(s1,s2)<<'\n';
	}
	return 0;
}
