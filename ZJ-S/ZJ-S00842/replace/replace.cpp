#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;
string s1[200009];
int snum1[200009];
string s2[200009];
int snum2[200009];
int ans1=0;
string s_cut(string s,int l,int r){
	string now="";
	for(;l<=r;l++){
		now=now+s[l-1];
	}
	return now;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		snum1[i]=s1[i].size();
		snum2[i]=s2[i].size();
	}	
	for(int i=1;i<=q;i++){
		string l1="",l2="";
		cin>>l1>>l2;
		ans1=0;
		string ss="";
		for(int sl=0;sl<=l1.size();sl++){
			if(sl){
				ss=ss+l1[sl-1];
			}
			for(int k=1;k<=n;k++){
				string snext=ss+s2[k]+s_cut(l1,sl+snum1[k]+1,l1.size());
				string snow=ss+s1[k]+s_cut(l1,sl+snum2[k]+1,l1.size());
				if(snext==l2 && snow==l1){
					ans1++;
					k+=n;
				}
			}
		}
		cout<<ans1<<'\n';
	}
	return 0;
} 
