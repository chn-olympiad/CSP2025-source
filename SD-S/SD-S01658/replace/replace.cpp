#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=2e5+5;
string s1[N],s2[N],t1[N],t2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;++i){
		cin>>t1[i]>>t2[i];
		string x=t1[i];
		int ret=0;
		for(int j=0;j<(int)x.size();++j){
			for(int k=1;k<=n;++k){
				if(j+(int)s1[k].size()-1>=(int)x.size())
					continue;
				string fk="";
				for(int m=j;m<=j+(int)s1[k].size()-1;++m)
					fk+=x[m];
				if(fk==s1[k]){
					string now=x;
					for(int m=j;m<=j+(int)s1[k].size()-1;++m)
						now[m]=s2[k][m-j];
					if(now==t2[i])
						++ret;
				}
			}
		}
		cout<<ret<<"\n";
	}
	return 0;
}
