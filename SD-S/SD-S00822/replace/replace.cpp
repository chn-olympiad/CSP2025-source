#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
string sx,sy;
map<pair<string,string>,int>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sx>>sy;
		if(sx==sy)continue;
		int l=0,r=sx.size()-1;
		while(sx[l]==sy[l])l++;
		while(sx[r]==sy[r])r--;
		mp[make_pair(sx.substr(l,r-l+1),sy.substr(l,r-l+1))]+=1;
	} 
	for(int i=1;i<=q;i++){
		cin>>sx>>sy;
		if(sx.size()!=sy.size()){
			cout<<"0\n";
			continue;
		}
		int l=0,r=sx.size()-1;
		while(sx[l]==sy[l])l++;
		while(sx[r]==sy[r])r--;
		cout<<mp[make_pair(sx.substr(l,r-l+1),sy.substr(l,r-l+1))]<<"\n";
	}
	return 0;
}
/*
我不会AAAAAAA！
怎么这么难啊！！！！！！
坠机！！！！！！
搞不好要AFO了朋友们
祝我顺利QAQ
球球了让我进一次NOIP吧…… 
60+16+0+0…… 
*/ 
