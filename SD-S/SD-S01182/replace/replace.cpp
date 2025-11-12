#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long 
#define ll long long
#define pii pair<int,int>
#define fi first 
#define se second
#define pb emplace_back

const int N=200010,B=31,C=100000007,D=1292137181;

string s[N][3],t[N][3];

int n,q,ha[N*30],pw[N*30],bb[N*30],mx;

vector<pii> dp[N*30];

unordered_map<int,int>mp,pre,you,cc;

unordered_map<int,int> pp;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;pw[0]=1;
		for(int i=1;i<=5000000;i++)
	pw[i]=pw[i-1]*B;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int k=0,n1=s[i][1].size();
		for(int j=0;j<n1;j++){
			k=k*B+(s[i][1][j]-'a'+1+(s[i][2][j]-'a'+1)*C);
			you[k]++;
		}
		if(you[k]>=2){
			bb[i]=1;
		}
		mp[k]++;
	}
	pre[0]=0;
	for(int i=1;i<=n;i++){
		if(bb[i]==1)continue;
		int k=0,n1=s[i][1].size(),num=0;
		mx=max(mx,n1-1);
		for(int j=0;j<n1;j++){
			int lst=k;
			k=k*B+(s[i][1][j]-'a'+1+(s[i][2][j]-'a'+1)*C);
//			fa[k]=lst;
//			if(lst==83&&k==3468)return 0;
			if(pp[k*D+lst]==0ll)
			dp[j].push_back({k,lst});
			pp[k*D+lst]=1;
//			num+=mp[k];//you[k]=1;
//			cout<<k<<" ";
//			pre[k]+=num;
		}
//		cout<<endl;
//		pre[k]=num;
	}
//	cout<<mx<<endl;
	for(int i=0;i<=mx;i++){
		for(auto o:dp[i]){
			int v=o.fi,fa=o.se;
			pre[v]+=pre[fa];
//			cout<<pre[v]<<endl;
//			assert(pre[v]<=n);
//			cout<<pre[v]<<" "<<pre[fa]<<" "<<v<<" "<<fa<<endl;
			if(cc[v]==0)pre[v]+=mp[v],cc[v]=1;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
		ll ans=0; 
		int n1=t[i][1].size();
		ll qian=-1,hou=-1;
		for(int j=0;j<n1;j++){
			if(t[i][1][j]!=t[i][2][j]){
				if(qian==-1)qian=j;
				hou=j;
			}
			if(j)ha[j]=(ha[j-1]*B);
			else ha[j]=0;
			ha[j]=(ha[j]+(t[i][1][j]-'a'+1+(t[i][2][j]-'a'+1)*C));
//			cout<<ha[j]<<" ";
		}
//		cout<<endl;
		for(ll j=0;j<=qian;j++){
			ll l=j,r=n1-1,res=0;
			while(l<=r){
				ll mid=(l+r)>>1;
				if(you[(ha[mid]-((j-1<0?0:ha[j-1])*pw[mid-j+1]))])res=mid,l=mid+1;
				else r=mid-1;
			}
//			cout<<res<<"!\n";
			//我们找到了一个最远的位置，可以记录一下他的pre,并且需要其>=hou 
			if(res<hou)continue;
			int chang=hou-j;
			ans+=pre[(ha[res]-((j-1<0?0:ha[j-1])*pw[res-j+1]))];//int kk=pre[(ha[res]-((j-1<0?0:ha[j-1])*pw[res-j+1]))];
//			cout<<pre[(ha[res]-((j-1<0?0:ha[j-1])*pw[res-j+1]))]<<"?\n";
			if(chang!=0){
				ll R=j+chang-1;
				int val=(ha[R]-((j-1<0?0:ha[j-1])*pw[R-j+1]));
//				cout<<j<<" "<<val<<" "<<pre[val]<<"\n";
				ans=(ans-pre[val]);
//				int kkk=pre[val];
//				assert(kk<kkk);
			}
		}
//		for(int i=0;i<n1;i++)ha[i]=0;
		cout<<ans<<"\n";
	}
	return 0;
}
