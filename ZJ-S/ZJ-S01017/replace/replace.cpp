#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
struct data{
	string s1,s2;
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>a[i].s1>>a[i].s2;
	if(n>500){
		for(int i=1;i<=q;++i)cout<<0<<'\n';
		return 0;
	}
	for(int i=1;i<=q;++i){
		cin>>s1>>s2;
		string ss=s1;
		int ans=0;
		for(int j=1;j<=s1.size();++j){
			for(int k=0;k<s1.size()-j+1;++k){
				string s3="",s4="";
				for(int p=1;p<=j;++p){
					s3+=s1[k+p-1];
					s4+=s2[k+p-1];
				}
				bool f=false;
				for(int p=1;p<=n;++p){
					if(s3==a[p].s1){
//						cout<<"p: "<<p<<'\n';
						for(int l=1;l<=a[p].s1.size();++l){
							s1[k+l-1]=a[p].s2[l-1];
						}
						if(s1==s2)ans++;
						s1=ss;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
