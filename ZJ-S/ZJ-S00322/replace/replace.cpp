#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=2e5+10;
string s[N][3];
int s_l[N][3][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int l2=0,r2=s[i][2].size()-1;
		while(s[i][1][l2]==s[i][2][l2])l2++;
		while(s[i][1][r2]==s[i][2][r2])r2--;
		s_l[i][1][1]=l2;
		s_l[i][1][2]=r2;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int l1=0,r1=t1.size()-1;
		while(t1[l1]==t2[l1])l1++;
		while(t1[r1]==t2[r1])r1--;
		int ans=0;
		for(int i=1;i<=n;i++){
			int l2=s_l[i][1][1];
			int r2=s_l[i][1][2];
			if(r1-l1+1!=r2-l2+1)continue;
			if(t1.size()<s[i][1].size())continue;
			int res=0;
			for(int j=0;j<r1-l1+1;j++){
				if(t1[l1+j]==s[i][1][l2+j]&&t2[l1+j]==s[i][2][l2+j]||
				   t2[l1+j]==s[i][1][l2+j]&&t1[l1+j]==s[i][2][l2+j])res++;
			}
			int flag=1;
			for(int j=l2;j>=0;j--){
				if(t1[l1-j]!=s[i][1][l2-j])flag=0;
			}
			for(int j=1;j<s[i][1].size()-r2&&j+r1<s[i][1].size();j++){
				if(t1[j+r2]!=s[i][1][j+r1])flag=0;
			}
			if(res==r1-l1+1&&flag)ans++;
		}
		cout<<ans<<endl;
	}
}
