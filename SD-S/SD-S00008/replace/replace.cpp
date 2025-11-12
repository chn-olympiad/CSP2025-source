#include<bits/stdc++.h>
using namespace std;
string bh[200005][5];
string t1,t2;
int n,q;
long long ans;
int nx[5000006];
void jh(string s,int l,int r,string th);
void find(string s,string cz,string th){
	int n=cz.size();
	int now=0;
	cz=' '+cz;
	for(int i=2;i<=n;i++){
		while(now!=0&&cz[i]!=cz[now+1])now=nx[now];
		if(cz[i]==cz[now+1])nx[i]=++now;
		else nx[i]=now;
	}
	now=0;
	for(int i=0;i<s.size();){
		while(now<n&&s[i+now]==cz[now+1])now++;
		if(now==n){
			jh(s,i,i+n-1,th);
		}
		if(now==0)i++;
		i+=now-nx[now];
		now=nx[now];
	}
//	string t;
//	for(int i=0;i<cz.size();i++){
//		t+=s[i];
//	}
//	if(t==cz){
//		jh(s,0,cz.size()-1,th);
//	}
//	for(int i=cz.size();i<s.size();i++){
//		string l;
//		for(int j=1;j<t.size();j++){
//			l+=t[j];
//		}
//		l+=s[i];
//		t=l;
//		if(t==cz){
//			jh(s,i-cz.size()+1,i,th);
//		}
//	}
}
void dfs(string s){
	for(int i=1;i<=n;i++){
		find(s,bh[i][1],bh[i][2]);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>bh[i][1]>>bh[i][2]; 
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		ans=0;
		dfs(t1);
		cout<<ans<<"\n";
	}
	return 0;
}
void jh(string s,int l,int r,string th){
	for(int i=l;i<=r;i++){
		s[i]=th[i-l];
	}
	if(s==t2){
		ans++;
	}
}
