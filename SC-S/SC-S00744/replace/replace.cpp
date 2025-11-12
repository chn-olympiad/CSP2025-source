#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s[200010],c[200010];
unsigned int h[200010];
vector<int>mb[1000010],mp[1000010];
unsigned int hh[200010],pp[200010];
unsigned int Hh[200010];
unsigned int hH[200010];
inline unsigned int gethash(int l,int r){
	return hh[r]-hh[l-1]*pp[r-l+1];
} 
inline unsigned int gethash2(int l,int r){
	return Hh[r]-Hh[l-1]*pp[r-l+1];
} 
inline unsigned int gethash3(int l,int r){
	return hH[r]-hH[l-1]*pp[r-l+1];
} 
unordered_map<unsigned int,int>mmp;
//unordered_map<unsigned int,vector<int> >mb;//记录最后 6 个的 hash 值和最后的 b 出现的两个位置（加到 hash 末尾） 
//unordered_map<unsigned int,vector<int> >mp;//记录没有出现 b 的最后 6 个的 hash 值 
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int l;
		cin>>s[i]>>c[i],l=s[i].size(),s[i]=" "+s[i],c[i]=" "+c[i];
		int poss=l+1,posc=l+1;
		for(int j=1;j<=l;j++){
			h[i]=h[i]*131+(s[i][j]-'a')*29+c[i][j]-'a';
			if(s[i][j]=='b') poss=j;
			if(c[i][j]=='b') posc=j;
		}
		unsigned int H=0;
		for(int j=max(1ll,l-6);j<=l;j++) H=H*131+(s[i][j]-'a')*29+c[i][j]-'a';
		if(poss!=l+1 && posc!=l+1){
			H=H*131+l-poss,H=H*131+l-posc;
			H%=999983;
			mb[H].push_back(i);
		}
		else{
			H%=999983;
			mp[H].push_back(i);
		}
//		cout<<h[i]<<"\n";
	}
	for(int i=1;i<=m;i++){
		string p,q;
		cin>>p>>q;
		if(p.size()!=q.size()) cout<<"0\n";
		else{
			int l=p.size();
			p=" "+p,q=" "+q; 
			int posp=l+1,posq=l+1;
			pp[0]=1;
			int ans=0;
//			mmp.clear();
			for(int i=1;i<=l;i++) hh[i]=hh[i-1]*131+(p[i]-'a')*29+q[i]-'a',pp[i]=pp[i-1]*131;
			for(int i=1;i<=l;i++) Hh[i]=Hh[i-1]*131+(p[i]-'a');
			for(int i=1;i<=l;i++) hH[i]=hH[i-1]*131+(q[i]-'a');
			for(int i=1;i<=l;i++){
				if(p[i]=='b') posp=i;
				if(q[i]=='b') posq=i;
				if(gethash2(i+1,l)!=gethash3(i+1,l)) continue;
				mmp.clear();
				for(int j=i;j>=max(i-6,1ll);j--){
					if(posp!=l+1 && posq!=l+1){
						unsigned int H=gethash(j,i);
						H=H*131+i-posp,H=H*131+i-posq;
						H%=999983;
						for(int k=0;k<mb[H].size();k++){
							int id=mb[H][k];
							int L=s[id].size()-1;
//							cout<<i-L+1<<" "<<i<<" "<<id<<" "<<gethash(i-L+1,i)<<" "<<h[id]<<" "<<j<<"\n";
							if(i-L+1<1) continue;
							if(gethash(i-L+1,i)==h[id] && gethash2(1,i-L)==gethash3(1,i-L))
								if(!mmp[id]) mmp[id]=1,ans++;
						}
					}
						unsigned int H=gethash(j,i);
						H%=999983;
//						for(int k=1;k<=n;k++){
						for(int k=0;k<mp[H].size();k++){
							int id=mp[H][k];
							int L=s[id].size()-1;
//							cout<<i-L+1<<" "<<i<<" "<<id<<" "<<gethash(i-L+1,i)<<" "<<h[id]<<" "<<j<<"\n";
							if(i-L+1<1) continue;
							if(gethash(i-L+1,i)==h[id] && gethash2(1,i-L)==gethash3(1,i-L))
								if(!mmp[id]) mmp[id]=1,ans++;
						}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}