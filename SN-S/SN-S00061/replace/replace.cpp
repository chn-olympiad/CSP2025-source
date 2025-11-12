#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+5,M=5e6+5,c=1145141;
int n,q,flg=1;ull qc[M],hsa[N],hsb[N],hta[M],htb[M];
unordered_map<int,int>mp;unordered_map<ull,int>mc,md;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q,qc[0]=1;
	for(int i=1;i<M;i++) qc[i]=qc[i-1]*c;
	for(int i=1;i<=n;i++){
		string sa,sb;int m;
		cin>>sa>>sb,m=sa.size();
		for(int j=0,fl=0;j<m;j++){
			if(sa[j]!=sb[j]&&!fl) fl=1;
			if(fl) hsb[i]=hsb[i]*c+sa[j]*26+sb[j]-(int)'a'*27+1;
			else hsa[i]=hsa[i]*c+sa[j]-'a'+1;
		}int numa=0,numb=0,ida,idb;
		for(int j=0;j<m;j++){
			flg&=(sa[j]<'b'&&sb[j]<'b');
			if(sa[j]=='b') numa++,ida=j;
			if(sb[j]=='b') numb++,idb=j;
		}flg&=(numa==1&&numb==1),mp[ida-idb]++;
	}if(flg){
		while(q--){
			string sa,sb;cin>>sa>>sb;int ida,idb;
			if(sa.size()!=sb.size()){cout<<"0\n";continue;}
			for(int i=1;sa[i];i++){
				if(sa[i]=='b') ida=i;
				if(sb[i]=='b') idb=i;
			}cout<<mp[ida-idb]<<"\n";
		}return 0;
	}while(q--){
		string sa,sb;cin>>sa>>sb;int fs=0,ed=0,ans=0;
		if(sa.size()!=sb.size()){cout<<"0\n";continue;}
		for(int i=0;sa[i];i++) hta[i+1]=hta[i]*c+sa[i]-'a'+1;
		for(int i=0;sa[i];i++) htb[i+1]=htb[i]*c+sa[i]*26+sb[i]-(int)'a'*27+1;
		for(int i=0;sa[i];i++) if(sa[i]!=sb[i]){
			if(!fs) fs=i+1;ed=i+1;
		}mc.clear(),md.clear();
		for(int i=ed;i<=sa.size();i++)
			mc[htb[i]-htb[fs-1]*qc[i-fs+1]]=1;
		for(int i=1;i<=fs;i++)
			md[hta[fs-1]-hta[i-1]*qc[fs-i]]=1;
		for(int i=1;i<=n;i++)
			if(md[hsa[i]]&&mc[hsb[i]]) ans++;
		cout<<ans<<"\n";
	}return 0;
}
