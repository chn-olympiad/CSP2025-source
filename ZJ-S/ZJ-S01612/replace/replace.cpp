#include<bits/stdc++.h>
#define int long long
#define ull long long
using namespace std;
constexpr int N=5e6+5,M=2e5+5,base=1331,mod=1e9+7;
mt19937 rnd(time(NULL));
int n,q,len[M],rd[122],tot;
vector<int>has[N][2],hass[2];
int f[N],invv,inv[N],cha[M],fl[M],fr[M],l[M],r[M];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
int gethas(int id,int w,int l,int r){
	return (has[id][w][r]-has[id][w][l-1]+mod)*inv[l-1]%mod;
}
int gethas2(int w,int l,int r){
	return (hass[w][r]-hass[w][l-1]+mod)*inv[l-1]%mod;
}
unordered_map<int,int>mp;
vector<int>id[N];
unordered_map<int,int>mpp[N];
unordered_map<int,bool>mp1,mp2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
//	for(int i='a';i<='z';i++) rd[i]=rnd()%mod;
	for(int i='a';i<='z';i++) rd[i]=i;
	cin>>n>>q;f[0]=1;inv[0]=1;invv=ksm(base,mod-2);
	for(int i=1;i<=n;i++) f[i]=f[i-1]*base%mod,inv[i]=inv[i-1]*invv%mod;
	int d=rnd()%mod;
	for(int i=1;i<=n;i++){
		string s0,s1;
		cin>>s0>>s1;
		len[i]=s0.size();
		has[i][0].push_back(0),has[i][1].push_back(0);
		int ll=0,rr=0;
		for(int j=0;j<len[i];j++){
			int x=(has[i][0][j]+f[j]*rd[s0[j]])%mod,y=(has[i][1][j]+f[j]*rd[s1[j]])%mod;
			has[i][0].push_back(x),has[i][1].push_back(y);
			if(s0[j]!=s1[j]&&ll==0) ll=j+1;
			if(s0[j]!=s1[j]) rr=j+1;
//			cout<<has[i][0][j+1]<<" "<<has[i][1][j+1]<<"\n";
		}
		l[i]=ll,r[i]=rr;
		cha[i]=(gethas(i,0,ll,rr)*f[rr-ll+1]+gethas(i,1,ll,rr))%mod;
		fl[i]=gethas(i,0,1,ll-1),fr[i]=gethas(i,0,rr+1,len[i]);
		if(mp[cha[i]]==0){
			mp[cha[i]]=++tot;
			id[tot].push_back(i);
			mpp[tot][fl[i]*d+fr[i]]++;
		}else{
			id[mp[cha[i]]].push_back(i);
			mpp[mp[cha[i]]][fl[i]*d+fr[i]]++;
		}
//		cout<<cha[i]<<"\n";
	}
	while(q--){
		string t[2];
		cin>>t[0]>>t[1];
		mp1.clear(),mp2.clear();
		int lenn=t[0].size();
		hass[0].clear(),hass[1].clear();
		hass[0].push_back(0),hass[1].push_back(0);
		int ll=0,rr=0;
		for(int i=0;i<lenn;i++){
			int x=(hass[0][i]+f[i]*rd[t[0][i]])%mod,y=(hass[1][i]+f[i]*rd[t[1][i]])%mod;
			hass[0].push_back(x),hass[1].push_back(y);
			if(t[0][i]!=t[1][i]&&ll==0) ll=i+1;
			if(t[0][i]!=t[1][i]) rr=i+1;
		}
		int chaa=(gethas2(0,ll,rr)*f[rr-ll+1]+gethas2(1,ll,rr))%mod;
		int ans=0,x=mp[chaa];
		if(!x){
			cout<<"0\n";
			continue;
		}
		if(ll*rr<=id[x].size()){
			for(int i=1;i<=ll;i++){
				int a=gethas2(0,i,ll-1)*d;
				for(int i=rr;i<=lenn;i++){
					int b=gethas2(0,rr+1,i);
					ans+=mpp[x][a+b];
				}
			}
		}else{
			for(int i=1;i<=ll;i++){
				mp1[gethas2(0,i,ll-1)]=1;
			}
			for(int i=rr;i<=lenn;i++){
				mp2[gethas2(0,rr+1,i)]=1;
			}
			if(x){
				for(int i:id[x]){
					if(mp1[fl[i]]&&mp2[fr[i]]) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
