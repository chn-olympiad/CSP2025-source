#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,HM1=131,HM2=13331,MOD=1e9+7;
int n,q;
string s[3][N];
int ml[N],mr[N];
int dl1[N],dl2[N],dr1[N],dr2[N];
map<pair<pii,pii>,vector<int> >mp;
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[1][i]>>s[2][i];
		if(s[1][i]==s[2][i])continue;
		for(int j=0,len=s[1][i].size();j<len;j++){
			if(s[1][i][j]!=s[2][i][j]){ml[i]=j;break;}
		}
		for(int j=s[1][i].size()-1;j>=0;j--){
			if(s[1][i][j]!=s[2][i][j]){mr[i]=j;break;}
		}
		for(int j=ml[i];j<=mr[i];j++){
			dl1[i]=(1ll*dl1[i]*HM1%MOD+(s[1][i][j]-96))%MOD;
			dl2[i]=(1ll*dl2[i]*HM2%MOD+(s[1][i][j]-96))%MOD;
			dr1[i]=(1ll*dr1[i]*HM1%MOD+(s[2][i][j]-96))%MOD;
			dr2[i]=(1ll*dr2[i]*HM2%MOD+(s[2][i][j]-96))%MOD;
		}
		mp[{{dl1[i],dl2[i]},{dr1[i],dr2[i]}}].push_back(i);
	}
	string t1,t2;
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){cout<<0<<endl;continue;}
		int l=0,r=0;
		for(int j=0,len=t1.size();j<len;j++){
			if(t1[j]!=t2[j]){l=j;break;}
		}
		for(int j=t1.size()-1;j>=0;j--){
			if(t1[j]!=t2[j]){r=j;break;}
		}
		int l1=0,l2=0,r1=0,r2=0;
		for(int j=l;j<=r;j++){
			l1=(1ll*l1*HM1%MOD+(t1[j]-96))%MOD;
			l2=(1ll*l2*HM2%MOD+(t1[j]-96))%MOD;
			r1=(1ll*r1*HM1%MOD+(t2[j]-96))%MOD;
			r2=(1ll*r2*HM2%MOD+(t2[j]-96))%MOD;
		}
		auto S=mp[{{l1,l2},{r1,r2}}];
		int cnt=0;
		for(auto i:S){
			if(ml[i]>l)continue;
			bool flag=0;
			for(int j=ml[i]-1,k=l-1;j>=0;j--,k--){
				if(s[1][i][j]!=t1[k]){flag=1;break;}
			}if(flag)continue;
			if(s[1][i].size()-mr[i]>t1.size()-r)continue;
			for(int j=mr[i]+1,k=r+1,len=s[1][i].size();j<len;j++,k++){
				if(s[1][i][j]!=t1[k]){flag=1;break;}
			}if(flag)continue;
			cnt++;
		}cout<<cnt<<endl;
	}
	return 0;
}
