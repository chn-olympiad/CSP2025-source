//[HRH]'s Code
#include<bits/stdc++.h>
using namespace std;
const int N=5e6+100;
const long long Q=998244353;
long long n,m,T,op;
map<string,vector<string>>v;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		v[s1].push_back(s2);
	}
	while(m--){
		string x,y,k="";
		cin>>x>>y;op=0;
		for(int i=0;i<x.size();i++){
			string p="";
			for(int j=i;j<x.size();j++){
				string t="";p+=x[j];
				if(!v[p].size())continue;
				for(int l=j+1;l<x.size();l++)t+=x[l];
				for(int l=0;l<v[p].size();l++){
					if(k+v[p][l]+t==y)op++;
				}
			}k+=x[i];
		}printf("%lld\n",op);
	}
	return 0;
}
/**/

