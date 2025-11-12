#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,l,r;
string t1,t2,r1,r2,s1,s2;
map<string,map<string,ll> > a;
void work(string &str1,string &str2){
	r1.clear(),r2.clear();
	l=r=-1;
	for(ll j=0;j<str1.size();j++)
		if(str1[j]!=str2[j]){
			if(l==-1) l=j;
			r=j;
		}
	for(ll i=l;i<=r;i++)
		r1+=str1[i],r2+=str2[i];
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s1>>s2;
		work(s1,s2);
		if(l!=-1) a[r1][r2]++;
	}for(ll i=1;i<=q;i++){
		cin>>t1>>t2;
		work(t1,t2);
		cout<<a[r1][r2]<<'\n';
	}return 0;
}
