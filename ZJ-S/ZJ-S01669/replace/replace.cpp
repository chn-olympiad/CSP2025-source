#include<bits/stdc++.h>
using namespace std;
string s[200100][3],q[200100][3];
int n,m;
struct node{
	string p;
	int l,r;
	
}o;
map<string , vector<node> >t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string p="";	
		int l=0,r;
		cin>>s[i][1]>>s[i][2];
		r=s[i][1].length()-1;
		while(s[i][1][l]==s[i][2][l]&&l<s[i][1].length())l++;
		while(s[i][1][r]==s[i][2][r]&&r>=0)r--;
		for(int j=l;j<=r;j++)p=p+s[i][1][j];
		for(int j=l;j<=r;j++)p=p+s[i][2][j];
//		cout<<p<<"\n";
		o.p=s[i][1],o.l=l,o.r=r;
		t[p].push_back(o);
	}
	for(int i=1;i<=m;i++){
		string p="";
		int l=0,r;
		cin>>q[i][1]>>q[i][2];
		if(q[i][1].length()!=q[i][2].length()){
			cout<<0<<"\n";
			continue;
		}
		r=q[i][1].length()-1;
		while(q[i][1][l]==q[i][2][l]&&l<q[i][1].length())l++;
		while(q[i][1][r]==q[i][2][r]&&r>=0)r--;
		for(int j=l;j<=r;j++)p=p+q[i][1][j];
		for(int j=l;j<=r;j++)p=p+q[i][2][j];
//		cout<<"\n"<<p<<" "<<q[i][1]<<"\n";
		int ans=0;
		for(int x=0;x<t[p].size();x++){
			o=t[p][x];
			bool flag=true;
//			cout<<o.p<<" "<<o.l<<"\n";
			for(int y=0;y<o.p.length();y++){
				if(o.p[y]!=q[i][1][y+l-o.l]){
//					cout<<o.p[y]<<" "<<y+l-o.l<<"\n";
					flag=false;
					break;
				}
			}
			if(flag)ans++;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
