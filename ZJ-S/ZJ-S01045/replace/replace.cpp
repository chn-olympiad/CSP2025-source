#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
//q*l2?
//B:q
int n,q;
int bas;
int w[5000005];
int hs[200005];
string s[200005][2],tin[200005][2];
int hss[5000005];
map<int,int>ctbi;
int geths(int l,int r){
	return (hss[l]-hss[r]*w[r-l]%mod+mod)%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0)*114514);
	bas=(rand()%20+20)%20+30;
	w[0]=1;
	for(int i=1;i<=5000000;i++){
		w[i]=w[i-1]*bas%mod;
	}
	cin>>n>>q;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		int m=s[i][0].size();
		s[i][0]=" "+s[i][0];
		bool cb=0;
		for(int j=m;j>0;j--){
			hs[i]=(hs[i]*bas%mod+s[i][0][j])%mod;
			if(s[i][0][j]!='a'&&s[i][0][j]!='b')f=0;
			if(cb&&s[i][0][j]=='b')f=0;
			else if(s[i][0][j]=='b')cb=1;
		}
		if(!cb)f=0;
		if(!f)continue;
		cb=0;
		for(int j=m-1;j>=0;j--){
			if(s[i][1][j]!='a'&&s[i][1][j]!='b'){
				f=0;
				break;
			}
			if(cb&&s[i][1][j]=='b'){
				f=0;
				break;
			}
			else if(s[i][1][j]=='b')cb=1;
		}
		if(!cb)f=0;
	}
	for(int i=1;i<=q;i++){
		cin>>tin[i][0]>>tin[i][1];
		tin[i][0]=" "+tin[i][0];
		tin[i][1]=" "+tin[i][1];
		if(!f)continue;
		bool cb=0;
		for(int j=tin[i][0].size()-1;j>0;j--){
			if(tin[i][0][j]!='a'&&tin[i][0][j]!='b'){
				f=0;
				break;
			}
			if(cb&&tin[i][0][j]=='b'){
				f=0;
				break;
			}
			else if(tin[i][0][j]=='b')cb=1;
		}
		if(!cb)f=0;
		if(!f)continue;
		cb=0;
		for(int j=tin[i][1].size()-1;j>0;j--){
			if(tin[i][1][j]!='a'&&tin[i][1][j]!='b'){
				f=0;
				break;
			}
			if(cb&&tin[i][1][j]=='b'){
				f=0;
				break;
			}
			else if(tin[i][1][j]=='b')cb=1;
		}
		if(!cb)f=0;
	}
	//if(!f){
		for(int tt=1;tt<=q;tt++){
			string t1,t2;
			t1=tin[tt][0];
			t2=tin[tt][1];
			if(t1.size()!=t2.size()){
				cout<<"0\n";
				continue;
			}
			int m=t1.size()-1;
			for(int j=m;j>0;j--){
				hss[j]=(hss[j+1]*bas%mod+t1[j])%mod;
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j+s[i][1].size()-1<=m;j++){
					if(geths(j,j+s[i][1].size())==hs[i]){
						string nt=t1.substr(0,j)+s[i][1]+t1.substr(j+s[i][1].size(),m-j-s[i][1].size()+1);
						if(nt==t2)ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		exit(0);
	//}
	/*
	for(int i=1;i<=n;i++){
		int m=s[i][1].size();
		s[i][1]=" "+s[i][1];
		int re1=0,re2=0;
		for(int j=1;j<=m;j++){
			if(s[i][0][j]=='b'){
				re1=j;
				break;
			}
		}
		for(int j=1;j<=m;j++){
			if(s[i][1][j]=='b'){
				re2=j;
				break;
			}
		}
		ctbi[re1-re2]++;
	}
	for(int tt=1;tt<=q;tt++){
		string t1,t2;
		t1=tin[tt][0];
		t2=tin[tt][1];
		int m=t1.size()-1;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int re1=0,re2=0;
		for(int j=1;j<=m;j++){
			if(t1[j]=='b'){
				re1=j;
				break;
			}
		}
		for(int j=1;j<=m;j++){
			if(t2[j]=='b'){
				re2=j;
				break;
			}
		}
		cout<<ctbi[re1-re2]<<"\n";
	}*/
	return 0;
}

