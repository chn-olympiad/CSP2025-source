#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define PII pair<ull,ull>
const int N = 5e6 + 5;
const int bas=113;
int n, q, nxt[202][2][202];
//string s1,s2;
string t1,t2;
string s[N][2];
//map <PII,int> mp;
//map <pair<string,string>,int> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		s[i][0]=' '+s[i][0];
		s[i][1]=' '+s[i][1];
		for(int j=2,k=0;j<s[i][0].size();j++){
			while(k&&s[i][0][k+1]!=s[i][0][j])k=nxt[i][0][k];
			if(s[i][0][k+1]==s[i][0][j])k++;
			nxt[i][0][j]=k;
		}
		for(int j=2,k=0;j<s[i][1].size();j++){
			while(k&&s[i][1][k+1]!=s[i][1][j])k=nxt[i][1][k];
			if(s[i][1][k+1]==s[i][1][j])k++;
			nxt[i][1][j]=k;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		t1=' '+t1;
		t2=' '+t2;
		int l=-1,r=-1;
		for(int j=1;j<t1.size();j++){
			if(t1[j]!=t2[j]){
				l=j;
				break;
			}
		}
		if(l==-1){
			cout<<"0\n";
			continue;
		}
		for(int j=t1.size()-1;j>=1;j--){
			if(t1[j]!=t2[j]){
				r=j;
				break;
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			for(int k=1,l1=0,l2=0;k<t1.size();k++){
				while(l1&&s[j][0][l1+1]!=t1[k])l1=nxt[j][0][l1];
				while(l2&&s[j][1][l2+1]!=t2[k])l2=nxt[j][1][l2];
				if(s[j][0][l1+1]==t1[k])l1++;
				if(s[j][1][l2+1]==t2[k])l2++;
				if(l1==s[j][0].size()-1&&l2==s[j][1].size()-1){
					if(k>=r&&k-l1+1<=l)ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
//	cin>>n>>q;
//	for(int i=1;i<=n;i++){
//		cin>>s1>>s2;
//		int l=-1,r=-1;
//		for(int j=0;j<s1.size();j++){
//			if(s1[j]!=s2[j]){
//				l=j;
//				break;
//			}
//		}
//		if(l==-1)continue;
//		for(int j=s1.size()-1;j>=0;j--){
//			if(s1[j]!=s2[j]){
//				r=j;
//				break;
//			}
//		}
//		t1="",t2="";
//		for(int j=l;j<=r;j++){
//			t1+=s1[j];
//			t2+=s2[j];
//		}
////		cout<<t1<<' '<<t2<<'\n';
//		mp[make_pair(t1,t2)]++;
////		ull has1=0,has2=0;
////		for(int i=l;i<=r;i++){
////			has1=(has1*bas)+(s1[i]-'a'+1);
////			has2=(has2*bas)+(s2[i]-'a'+1);
////		}
////		mp[make_pair(has1,has2)]++;
//	}
//	for(int i=1;i<=q;i++){
//		cin>>s1>>s2;
//		if(s1.size()!=s2.size()){
//			cout<<"0\n";
//			continue;
//		}
//		int l=-1,r=-1;
//		for(int j=0;j<s1.size();j++){
//			if(s1[j]!=s2[j]){
//				l=j;
//				break;
//			}
//		}
//		if(l==-1)continue;
//		for(int j=s1.size()-1;j>=0;j--){
//			if(s1[j]!=s2[j]){
//				r=j;
//				break;
//			}
//		}
//		t1="",t2="";
//		for(int j=l;j<=r;j++){
//			t1+=s1[j];
//			t2+=s2[j];
//		}
//		cout<<mp[make_pair(t1,t2)]<<'\n';
////		ull has1=0,has2=0;
////		for(int i=l;i<=r;i++){
////			has1=(has1*bas)+(s1[i]-'a'+1);
////			has2=(has2*bas)+(s2[i]-'a'+1);
////		}
////		if(mp[make_pair(has1,has2)]==360){
////			cout<<s1<<' '<<s2<<'\n';
//////			cout<<has1<<' '<<has2<<'\n';
////		}
////		cout<<mp[make_pair(has1,has2)]<<'\n';
//	}
	return 0;
}

