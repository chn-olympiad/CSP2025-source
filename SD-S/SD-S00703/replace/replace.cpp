#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
const int N=2e5+5;
const ull B=131;
const int M=5e6+5;
int n,q,sm[N];
ull A[M];
ull a1[N],a2[N];
ull b1[M],b2[M];
void solve(){
	cin>>n>>q;A[0]=1;
	for(int i=1;i<M;i++)
		A[i]=A[i-1]*B;
	string s1,s2,t1,t2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		sm[i]=s1.size();
		for(int j=0;j<sm[i];j++)
			a1[i]=a1[i]*B+(s1[j]-'a');
		for(int j=0;j<sm[i];j++)
			a2[i]=a2[i]*B+(s2[j]-'a');
//		cout<<a1[i]<<' '<<a2[i]<<'\n';
	}for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int tm=t1.size(),ans=0;
		for(int j=0;j<tm;j++)
			b1[j+1]=b1[j]*B+(t1[j]-'a');
		for(int j=0;j<tm;j++)
			b2[j+1]=b2[j]*B+(t2[j]-'a');
//		cout<<b1[tm]<<' '<<b2[tm]<<'\n';
		for(int j=1;j<=n;j++){
			for(int l=0;l+sm[j]-1<tm;l++){
				int r=l+sm[j]-1;
				if(a1[j]==b1[r+1]-b1[l]*A[sm[j]]&&
				a2[j]==b2[r+1]-b2[l]*A[sm[j]]&&
				b1[l]==b2[l]&&b1[tm]-b1[r+1]*A[tm-r-1]==b2[tm]-b2[r+1]*A[tm-r-1])
					ans++;
			}
		}cout<<ans<<'\n';
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	solve();return 0;
}
//yu shi zhen hao ke !!!

