#include<bits/stdc++.h>
using namespace std;
//freopen?
//long long?
//memset?
//KMP(?)(wrong)(I didn't study it yet)
//brute(right)(map in map)
string s1[200010],s2[200010],t1,t2;
int n,q;
map<string,map<string,int>>a;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int u=s1[i].size();
		int l=0,r=u-1;
		while(l<=r && s1[i][l]==s2[i][l])l++;
		while(r>=l && s1[i][r]==s2[i][r])r--;
		string d1=s1[i].substr(l,r-l+1),d2=s2[i].substr(l,r-l+1);
		s1[i]=d1;
		s2[i]=d2;
		a[s1[i]][s2[i]]++;
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int x=t1.size(),y=t2.size();
		if(x!=y){
			cout<<"0"<<endl;
			continue;
		}
		int l=0,r=x-1;
		while(l<=r && t1[l]==t2[l])l++;
		while(r>=l && t1[r]==t2[r])r--;
		t1=t1.substr(l,r-l+1);
		t2=t2.substr(l,r-l+1);
		cout<<a[t1][t2]<<endl;
	}
	return 0;
}