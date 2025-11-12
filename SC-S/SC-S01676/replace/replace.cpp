#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+5;
const int mod=1e9+7;
int n,q,ans;
string s1[mx],s2[mx];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		string x="",y="";
		ans=0;
		cin>>t1>>t2;
		int l=0,r=t1.size();
		for(int i=0;i<t1.size();i++){
			if(t1[i]==t2[i]){
				x+=t1[i];
				l=i;
			}
			else break;
		}
		for(int i=t1.size()-1;i>=0;i--){
			if(t1[i]==t2[i]){
				y+=t1[i];
				r=i;
			}
			else break;
		}
	//	cout<<l<<" "<<r<<'\n';
	while(l>=0&&r<=n){
		if(l==0&&r==t1.size())break;
		string q1="",q2="",q3="";
		string Q1="",Q2="",Q3="";
		for(int i=l+1;i<=r-1;i++)Q1+=t2[i];
		for(int i=l+1;i<=r-1;i++)q1+=t1[i];
		//cout<<1<<":"<<q1<<" "<<Q1<<'\n';
		for(int j=1;j<=n;j++)if(s1[j]==q1&&s2[j]==Q1)ans++;
		
		if(l-1>=0){
			for(int i=l;i<=r-1;i++)Q2+=t2[i];
			for(int i=l;i<=r-1;i++)q2+=t1[i];
		//	cout<<2<<":"<<q2<<" "<<Q2<<'\n';
			for(int j=1;j<=n;j++)if(s1[j]==q2&&s2[j]==Q2)ans++;
			l--;
		}
		
		if(r+1<=n){
			for(int i=l+1;i<=r;i++)Q3+=t2[i];
			for(int i=l+1;i<=r;i++)q3+=t1[i];
		//	cout<<3<<":"<<q3<<" "<<Q3<<'\n';
			for(int j=1;j<=n;j++)if(s1[j]==q3&&s2[j]==Q3)ans++;
			r++;
		}
	}
	for(int j=1;j<=n;j++)if(s1[j]==t1&&s2[j]==t2)ans++;
		cout<<ans<<'\n';
	}
	return 0;
}