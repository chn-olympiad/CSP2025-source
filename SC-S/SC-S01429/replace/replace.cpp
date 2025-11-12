#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
//#define int long long
using namespace std;
int n,m,nxt[2010][1010],l[2010];
string s1[200010],s2[200010],t1,t2;
bool vis[5000010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		l[i]=s1[i].length();
		s1[i]=" "+s1[i];
	}
	for(int k=1;k<=n;k++)
		for(int i=2,j=0;i<=l[k];i++){
			while(j&&s1[k][j+1]!=s1[k][i])
				j=nxt[k][j];
			if(s1[k][j+1]==s1[k][i])
				j++;
			nxt[k][i]=j;
		}
	while(m--){
		int ans=0;
		cin>>t1>>t2;
		t1=" "+t1;
		t2=" "+t2;
		for(int k=1;k<=n;k++)
			for(int i=1,j=0;i<t1.length();i++){
				while(j&&s1[k][j+1]!=t1[i])
					j=nxt[k][j];
				if(s1[k][j+1]==t1[i])
					j++;
				if(j==l[k]){
					string tt=t1;
//					cout<<"---"<<endl;
//					cout<<s1[k]<<endl;
//					cout<<t1<<endl;
//					cout<<t2<<endl;
//					cout<<s2[k]<<endl;
//					cout<<i-l[k]+1<<" "<<i<<endl;
//					cout<<"-!-"<<endl;
					bool f=1;
					for(int I=i-l[k]+1,J=0;I<=i;I++,J++)
						tt[I]=s2[k][J];
//					cout<<tt<<endl;
//					cout<<f<<" "<<tt.length()<<endl;
					for(int I=1;I<tt.length();I++)
						if(tt[I]!=t2[I]){
							f=0;
//							cout<<tt[I]<<" "<<t2[I]<<endl;
//							cout<<I<<"!"<<endl;
							break;
						}
					if(f)
						ans++;
					break;
				}
			}
		cout<<ans<<endl;
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
*/