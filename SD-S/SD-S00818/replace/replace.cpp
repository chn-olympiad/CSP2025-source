#include<bits/stdc++.h>
#define int long long
#define uint unsigned long long
#define lowbit(x) ((x)&-(x))
#define endl "\n"
using namespace std;
const int N=2e3+10;
int n,q;
string s[N][2],qs[2];
uint h[2][N][N],qh[2][N],pw[N];
uint ask_hash(uint h[],int l,int r){
	return h[r]-h[l]*pw[r-l];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;pw[0]=1;
	for(int i=1;i<=2000;i++)pw[i]=pw[i-1]*131;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		s[i][0]=" "+s[i][0];s[i][1]=" "+s[i][1];
		for(int k=1;k<s[i][0].size();k++){
			h[0][i][k]=h[0][i][k-1]*131+s[i][0][k];
			h[1][i][k]=h[1][i][k-1]*131+s[i][1][k];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qs[0]>>qs[1];int ans=0;
		qs[0]=" "+qs[0];qs[1]=" "+qs[1];
		for(int k=1;k<s[i][0].size();k++){
			qh[0][k]=qh[0][k-1]*131+qs[0][k];
			qh[1][k]=qh[1][k-1]*131+qs[1][k];
		}
		for(int k=1;k<=n;k++){
			int len=s[k][0].size()-1;
			for(int j=1;j+len-1<s[i][0].size();j++){
				uint lp=ask_hash(qh[0],1,j-1),lpp=ask_hash(qh[1],1,j-1);
				uint rp=ask_hash(qh[0],j+len,s[i][0].size()-1),rpp=ask_hash(qh[1],j+len,s[i][0].size()-1);
				if(lp!=lpp)break;if(rp!=rpp)continue;
				uint ls=ask_hash(qh[0],j,j+len-1),rs=ask_hash(qh[1],j,j+len-1);
				uint lss=ask_hash(h[0][k],1,len),rss=ask_hash(h[1][k],1,len);
				if(ls==lss&&rs==rss)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

