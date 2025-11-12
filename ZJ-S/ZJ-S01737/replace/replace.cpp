#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid(l,r) (l+r>>1)
#define lowbit(x) (x&-x)
using namespace std;
const int N=2e5+10,M=5e6+10,mod=1e9+7,base=13331;
const double eps=1e-1;
const long double pi=acos(-1);
int n,q,pre[M],suf[M];
string s[N][3],t[N][3];
map<pair<int,int>,int>cnt;
unsigned int hsh1[M],hsh2[M],hsh3[M],hsh4[M],pw[M];
int check(string x){
	int flg=0;
	for(int j=0;j<x.size();j++){
		if(x[j]!='a'&&x[j]!='b'){
			flg=1;
			break;
		}
		if(x[j]=='a')continue;
		if(!flg)flg=2;
		else{
			flg=1;
			break;
		}
	}
	if(flg==1||!flg)return 0;
	return 1;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++)cin>>t[i][1]>>t[i][2];
	int flag=0;
	for(int i=1;i<=n;i++){
		if(!check(s[i][1])||!check(s[i][2])){
			flag=1;
			break;
		}
	}
	for(int i=1;i<=q;i++){
		if(!check(t[i][1])||!check(t[i][2])){
			flag=1;
			break;
		}
	}
	pw[0]=1;
	for(int i=1;i<=5e6;i++)pw[i]=pw[i-1]*base;
	for(int i=1;i<=q;i++){
		if(t[i][1].size()!=t[i][2].size()){
			cout<<"0"<<endl;
			continue;
		}
		hsh3[0]=t[i][1][0]-'a'+1;
		hsh4[0]=t[i][2][0]-'a'+1;
		for(int j=1;j<t[i][1].size();j++){
			hsh3[j]=hsh3[j-1]*base+t[i][1][j]-'a'+1;
			hsh4[j]=hsh4[j-1]*base+t[i][2][j]-'a'+1;
		}
		if(t[i][1][0]!=t[i][2][0])pre[0]=0;
		else pre[0]=1;
		for(int j=1;j<t[i][1].size();j++){
			pre[j]=pre[j-1];
			if(t[i][1][j]!=t[i][2][j])pre[j]=0;
		}
		if(t[i][1][(int)t[i][1].size()-1]!=t[i][2][(int)t[i][1].size()-1])suf[(int)t[i][1].size()-1]=0;
		else suf[(int)t[i][1].size()-1]=1;
		for(int j=t[i][1].size()-2;j>=0;j--){
			suf[j]=suf[j+1];
			if(t[i][1][j]!=t[i][2][j])suf[j]=0;
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			hsh1[0]=s[j][1][0]-'a'+1;
			hsh2[0]=s[j][2][0]-'a'+1;
			for(int k=1;k<s[j][1].size();k++){
				hsh1[k]=hsh1[k-1]*base+s[j][1][k]-'a'+1;
				hsh2[k]=hsh2[k-1]*base+s[j][2][k]-'a'+1;
			}
			for(int k=0;k+(int)s[j][1].size()-1<t[i][1].size();k++){
				int l=k,r=k+(int)s[j][1].size()-1,val,flag=0;
				if(l!=0&&!pre[l-1])flag=1;
				if(r!=(int)t[i][1].size()-1&&!suf[r+1])flag=1;
				if(flag)continue;
				if(!l)val=hsh3[r];
				else val=hsh3[r]-hsh3[l-1]*pw[r-l+1];
				if(val!=hsh1[(int)s[j][1].size()-1])continue;
				if(!l)val=hsh4[r];
				else val=hsh4[r]-hsh4[l-1]*pw[r-l+1];
				if(val!=hsh2[(int)s[j][2].size()-1])continue;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
