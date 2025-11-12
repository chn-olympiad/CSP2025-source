#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define mkp make_pair
const int inf=2e15;
const int mul=911,mod=993244853;
int n,q;
string s[201000][2],ss1,ss2;
int len[201000],thl[201000],thr[201000];
int dif[201000],bec[201000];
int hsh[501000],hss[501000];
int fmul[501000];
int H(int l,int r,int lln){
	if(l<0||r>=lln) return -1;
	if(l)return ((hsh[r]-hsh[l-1]*fmul[r-l+1])%mod+mod)%mod;
	return hsh[r];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//system("fc replace.out replace4.ans");
	fmul[0]=1;
	for(int i=1;i<=500000;i++){
		fmul[i]=fmul[i-1]*mul%mod;
	}
	//cin>>n>>q;
	scanf("%lld %lld",&n,&q); 
	if(q<=20000000){
		for(int i=1;i<=n;i++){
			cin>>s[i][0]>>s[i][1];
			//scanf("%s %s",&s[i][0],&s[i][1]);
			len[i]=s[i][0].size();
			thl[i]=inf;
			for(int j=0;j<len[i];j++){
				hss[i]=hss[i]*mul+s[i][0][j];
				hss[i]%=mod;
				if(s[i][0][j]!=s[i][1][j]){
					thl[i]=min(thl[i],j);
					thr[i]=max(thr[i],j);
				}
			}
			for(int j=thl[i];j<=thr[i];j++){
				dif[i]=dif[i]*mul+s[i][0][j];
				dif[i]%=mod;
				bec[i]=bec[i]*mul+s[i][1][j];
				bec[i]%=mod;
			}
		}
		while(q--){
			cin>>ss1>>ss2;
			if(ss1.size()!=ss2.size()){
				cout<<0<<"\n";
				continue;
			}
			int tl=inf,tr=0,lln=ss1.size(),df=0,bc=0;
			for(int j=0;j<lln;j++){
				if(j)hsh[j]=hsh[j-1]*mul+ss1[j];
				else hsh[j]=ss1[j];
				hsh[j]%=mod;
				if(ss1[j]!=ss2[j]){
					tl=min(tl,j);
					tr=max(tr,j);
				}
			}for(int j=tl;j<=tr;j++){
				df=df*mul+ss1[j];
				df%=mod;
				bc=bc*mul+ss2[j];
				bc%=mod;
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(dif[i]==df&&bec[i]==bc){
					if(hss[i]==H(tl-thl[i],tr+len[i]-thr[i]-1,lln)) ans++;
				}
			}cout<<ans<<"\n";
		}
	}
 	return 0;
}
