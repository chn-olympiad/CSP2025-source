#include<bits/stdc++.h>
using namespace std;
int n,q;
string s;
string s1[200010],s2[200010];
string t1,t2;
int f1[200010],f2[200010];
void solve1(){
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int cnt=0;
		for(int j=1;j<=n;j++)
			for(int k=0;k<t1.size()-s1[j].size()+1;k++){
				if(t1.substr(k,s1[j].size())==s1[j]){
					s=t1;
					for(int o=k;o<=k+s1[j].size()-1;o++)
						s[o]=s2[j][o-k];
					if(s==t2)cnt++;
				}
			}
		cout<<cnt<<'\n';
	}
}
void solve2(){
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();i++){
			if(s1[i][j]=='b')f1[i]=j;
			if(s2[i][j]=='b')f2[i]=j;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int w1,w2;
		for(int j=0;j<t1.size();i++){
			if(t1[j]=='b')w1=j;
			if(t2[j]=='b')w2=j;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(w1-w2!=f1[i]-f2[i])continue;
			if(f1[i]>w1||s1[i].size()-f2[i]>t1.size()-w2)continue;
			cnt++;
		}
		cout<<cnt<<'\n';
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	if(n<=100)solve1();
	else solve2();
	return 0;
}
