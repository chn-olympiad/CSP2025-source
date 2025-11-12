#include <bits/stdc++.h>
using namespace std;
struct str{
	string st;
	string re;
};

bool check(string s1,string s2){
	if(s1.size()!=s2.size())
		return false;
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i])
			return false;
	} 
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	str s[n];
	for(int i=0;i<n;i++){
		cin>>s[i].st>>s[i].re;
	}
	str r[q];
	for(int i=0;i<q;i++){
		cin>>r[i].st>>r[i].re;
	}
	int sum[100001]={0};
	for(int i=0;i<q;i++){
		for(int j=0;j<n;j++){
			if(r[i].st.find(s[j].st)){
				string tmp;
				for(int i=0;i<r[i].st.find(s[j].st);i++)
					tmp+=r[i].st[i];
				tmp+=s[j].re;
				for(int i=r[i].st.find(s[j].st)+s[j].st.size();i<r[i].st.size();i++)
					tmp+=r[i].st[i];
				r[i].st=tmp;
				sum[i]++;
			}
		}
	}
	int sm=q;
	for(int i=0;i<q;i++){
		if(!check(r[i].st,r[i].re))
			cout<<0<<endl;
		else
			cout<<sum[i]<<endl;
	}
	return 0;
}
