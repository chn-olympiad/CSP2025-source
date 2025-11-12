#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int N=2000010,M=200010,bs=173;
string s1[M],s2[M];
char t1[N],t2[N];
vector<ull>hs1[M],hs2[M];
int len[N];
ull pw[N],ht1[N],ht2[N];
inline ull gets1(int id,int l,int r){
	return hs1[id][r]-hs1[id][l-1]*pw[r-l+1];
}
inline ull gets2(int id,int l,int r){
	return hs2[id][r]-hs2[id][l-1]*pw[r-l+1];
}
inline ull gett1(int l,int r){
	return ht1[r]-ht1[l-1]*pw[r-l+1];
}
inline ull gett2(int l,int r){
	return ht2[r]-ht2[l-1]*pw[r-l+1];
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<N;i++)pw[i]=pw[i-1]*bs;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
		len[i]=(int)s1[i].size()-1;
		hs1[i].resize(len[i]+2);
		hs2[i].resize(len[i]+2);
		hs1[i][0]=hs2[i][0]=0;
		for(int j=1;j<=len[i];j++){
			hs1[i][j]=hs1[i][j-1]*bs+s1[i][j];
			hs2[i][j]=hs2[i][j-1]*bs+s2[i][j];
		}
	}
	while(q--){
		cin>>t1+1>>t2+1;
		int tl=strlen(t1+1);
		if(strlen(t2+1)!=tl){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=tl;i++){
			ht1[i]=ht1[i-1]*bs+t1[i];
			ht2[i]=ht2[i-1]*bs+t2[i];
		}
		int l=1,r=tl;
		while(t1[l]==t2[l]&&l<=tl)l++;
		while(t1[r]==t2[r]&&r>=1)r--;
		int qwq=r-l+1,ans=0;
		for(int i=1;i<=n;i++){
			if(len[i]<qwq)continue;
			for(int j=0;j<=len[i]-qwq;j++){
				if(gets1(i,1,j)!=gets2(i,1,j))break;
				int L=l-j;
				int R=L+len[i]-1;
				if(L>=1&&R<=tl)
					if(gets1(i,1,len[i])==gett1(L,R)&&gets2(i,1,len[i])==gett2(L,R))
						ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
