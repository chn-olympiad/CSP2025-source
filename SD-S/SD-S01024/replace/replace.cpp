#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 19260817 , B = 31;
ll qpow(ll a,ll b){
	ll ans=1,base=a;
	while(b){
		if(b&1)ans=ans*base%mod;
		base=base*base%mod;
		b>>=1; 
	}
	return ans;
}
string s[200010][2];
int hsh[200010][2],n,q;
int h1[5000050],h2[5000050],bn[5000050],biv[5000050],cnt;
unordered_map<ll,int>mp;
pair<int,int>rr[200050];
void tohsh(int x){
	int n=s[x][0].size();
	for(int i=0;i<n;i++)hsh[x][0]=(1ll*hsh[x][0]*B+s[x][0][i]-'a'+1)%mod;
	for(int i=0;i<n;i++)hsh[x][1]=(1ll*hsh[x][1]*B+s[x][1][i]-'a'+1)%mod;
	mp[1ll*hsh[x][0]*(mod+1)+hsh[x][1]]++;
	if(hsh[x][0]==hsh[x][1])rr[++cnt]={hsh[x][0],n};
} 
int gethsh(int l,int r,int x){
	if(l==0)return x==1?h1[r]:h2[r]; 
	if(x==1)return (h1[r]-1ll*bn[r-l+1]*h1[l-1]%mod+mod)%mod;
	else return (h2[r]-1ll*bn[r-l+1]*h2[l-1]%mod+mod)%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=n;i++)tohsh(i);
	bn[0]=1;biv[1]=qpow(B,mod-2);
	for(int i=1;i<=5000000;i++)bn[i]=1ll*bn[i-1]*B%mod;
//	for(int i=2;i<=5000000;i++)biv[i]=1ll*biv[i-1]*biv[1]%mod; 
	//for(int i=1;i<=n;i++)cout<<hsh[i][0]<<" "<<hsh[i][1]<<endl;
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.size(),ans=0;
		int l=0,r=len-1;
		h1[0]=t1[0]-'a'+1,h2[0]=t2[0]-'a'+1;
		for(int i=1;i<len;i++)h1[i]=(1ll*h1[i-1]*B+t1[i]-'a'+1)%mod;
		for(int i=1;i<len;i++)h2[i]=(1ll*h2[i-1]*B+t2[i]-'a'+1)%mod;
	//	for(int i=0;i<len;i++)cout<<h1[i]<<" ";cout<<endl;
		while(l<len&&t1[l]==t2[l])++l;
		while(r>=0&&t1[r]==t2[r])--r;
		if(l>r){//t1==t2
			for(int j=1;j<=cnt;j++){
				int hr=rr[j].first,ll=rr[j].second;
				for(int i=0;i+ll<len;i++)ans+=gethsh(i,i+ll,1)==hr; 
			}
		}else{
		//	cout<<l<<" "<<r<<endl;
			for(int i=0;i<=l;i++){
				for(int j=len-1;j>=r;j--){
					ans+=mp[gethsh(i,j,1)*(mod+1)+gethsh(i,j,2)];
		//			cout<<i<<" "<<j<<" "<<gethsh(i,j,1)<<" "<<ans<<endl;
				}
			}
		} 
		// 虽然它样例 3 跑了 117.1s
		// 但是他对了 
		cout<<ans<<endl;
	}
	return 0;
}
// #include<bits\stdc++.h>
// 不敢笑 前一个坐我位置的真这么写的 
 

