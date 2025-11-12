#include<bits/stdc++.h>
using namespace std;
int n,q,L,R;
string s[200005],s1[200005],t,t1;
bool check(int l,int r,int x){
//	cout<<l<<" "<<r<<" "<<s[x]<<" "<<s1[x]<<"check\n";
	for(int i=l;i<=r;i++){
		if(s[x][i-l]!=t[i]||s1[x][i-l]!=t1[i])return false;
	}
	return true;
}
//int sf,s1f,sb,s1b,tf,t1f,tb,t1b,ssb[200005],ss1b[200005];
//bool chek(){
//	sb=s1b=tb=t1b=0;
//	for(int i=1;i<=n;i++){
//		sb=s1b=0;
//		for(int j=0;j<s[i].size();j++){
//			if(s[i][j]!='a'&&s[i][j]!='b')
//			return false;
//			if(s[i][j]=='b')sb+=1;
//		}
//		if(sb!=1)return false;
//		for(int j=0;j<s1[i].size();j++){
//			if(s1[i][j]!='a'&&s1[i][j]!='b')
//			return false;
//			if(s1[i][j]=='b')s1b+=1;
//		}
//		if(s1b!=1)return false;
//	}
//	for(int i=0;i<t.size();i++){
//		if(t[i]!='a'&&t[i]!='b')
//		return false;
//		if(t[i]=='b')tb+=1;
//	}
//	if(tb!=1)return false;
//	for(int i=0;i<t1.size();i++){
//		if(t1[i]!='a'&&t1[i]!='b')
//		return false;
//		if(t1[i]=='b')t1b+=1;
//	}
//	if(t1b!=1)return false;
//	tb=t1b=0;
//	return true;
//}
//void solve1(){
//	int ans=0;
//	for(int i=0;i<t.size();i++){
//		if(t[i]=='b')
//		tb=i;
//		if(t1[i]=='b')
//		t1b=i;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<s[i].size();j++)
//		if(s[i][j]=='b')ssb[i]=j;
//		for(int j=0;j<s1[i].size();j++)
//		if(s1[i][j]=='b')ss1b[i]=j;
//	}
//	for(int i=1;i<=n;i++){
//		if(tb-ssb[i]>0&&t1b-ss1b[i]>0&&t1b-tb==ssb[i]-ss1b[i]&&tb+s[i].size()-ssb[i]-1<=t.size()){
//			ans+=1;
//		}
//	}
//	cout<<ans<<"\n";
//}
void solve(){
//	if(chek()){
//		solve1();
//	}
//	else{
		for(int i=0;i<t.size();i++){if(t[i]!=t1[i]){L=i;break;}}
		for(int i=t.size()-1;i>=0;i--){if(t[i]!=t1[i]){R=i;break;}}
		bool p=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<t.size();j++){
				if(j<=L&&j+s[i].size()-1>=R&&t[j]==s[i][0]&&t1[j]==s1[i][0]&&check(j,j+s[i].size()-1,i)){
	//				cout<<i<<"**\n";
					ans+=1;
					continue;
				}
			}
		}
		cout<<ans<<"\n";
//	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	while(q--){
		cin>>t>>t1;
		solve();
	}
}
