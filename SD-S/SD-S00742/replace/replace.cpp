#include<bits/stdc++.h>
using namespace std;
int n,q;
string ti[200010][2];
int l2[200010];
int r2[200010];
string gett(int l,int r,string s){
	string t;
	for(int i=l;i<r;i++){
		t+=s[i];
	}
	return t;
}
int solve(){
	string s,t,ms,mt;
	cin>>s>>t;
	int len=s.size();
	int l=0,r=len,ans=0;
	for(int i=0;i<len;i++){
		if(s[i]!=t[i]){
			break;
		}
		l++;
	}
	for(int i=len-1;i>=0;i--){
		if(s[i]!=t[i]){
			break;
		}
		r--;
	}
	ms=gett(l,r,s);
	mt=gett(l,r,t);
	//cout<<":"<<ms<<endl<<":"<<mt<<endl;
	for(int i=1;i<=n;i++){
		string s1=ti[i][0];
		string t1=ti[i][1];
		int len1=s1.size();
		int l1=l2[i];
		int r1=r2[i];
		if(l1>=r1) continue;
		//cout<<gett(l1,r1,s1)<<";\n"<<gett(l1,r1,t1)<<";\n"; 
		if(gett(l1,r1,s1)!=ms||gett(l1,r1,t1)!=mt) continue;
		if(l1>l||len1-r1>len-r) continue;
		if(gett(l-l1,l,s)!=gett(0,l1,s1)||gett(r,r+len1-r1,s)!=gett(r1,len1,s1)) continue;
		ans++;
	}
	cout<<ans<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ti[i][0]>>ti[i][1];
	}
	for(int i=1;i<=n;i++){
		string s1=ti[i][0];
		string t1=ti[i][1];
		int len1=s1.size();
		int l1=0,r1=len1;
		for(int i=0;i<len1;i++){
			if(s1[i]!=t1[i]){
				break;
			}
			l1++;
		}
		for(int i=len1-1;i>=0;i--){
			if(s1[i]!=t1[i]){
				break;
			}
			r1--;
		}
		l2[i]=l1;
		r2[i]=r1;
	}
	for(int i=1;i<=q;i++){
		solve(); 
	}
	return 0;
}


