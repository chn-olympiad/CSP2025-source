#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
const int N=220000;
const int M=2.6e6;
const ull B=2333;
int n,q;
string s[N][3];
string tmps[N][3];
int tmpa[N];
int a[N];
string t1,t2;
ull H[M][3];
ull h[N][3];
ull qB[M];
pair<int,int>A[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>n>>q;
	qB[0]=1;
	for(register int i=1;i<M-100;++i)qB[i]=qB[i-1]*B;
	for(register int i=0;i<n;++i)cin>>s[i][0]>>s[i][1];
	for(register int i=0;i<n;++i)a[i]=s[i][1].length();
	for(register int i=0;i<n;++i)A[i]=make_pair(a[i],i);
	sort(A,A+n);
	for(register int i=0;i<n;++i)tmpa[i]=a[A[i].second];
	for(register int i=0;i<n;++i)tmps[i][0]=s[A[i].second][0];
	for(register int i=0;i<n;++i)tmps[i][1]=s[A[i].second][1];
	for(register int i=0;i<n;++i)a[i]=tmpa[i];
	for(register int i=0;i<n;++i)s[i][0]=tmps[i][0];
	for(register int i=0;i<n;++i)s[i][1]=tmps[i][1];
	for(register int i=0;i<n;++i){
		for(register int k=0;k<=1;++k){
			unsigned long long S=(s[i][k][0]-'a');
			for(register int j=1;j<a[i];++j){
				S=S*B+(s[i][k][j]-'a');
			}
			h[i][k]=S;	
//			cout<<i<<":"<<k<<" "<<h[i][k]<<endl;		
		}
	}
	int cnt=0;
	while(q--){
		cin>>t1>>t2;
		int L=1e9,R=-1;
		int m=t1.length();
		for(register int i=0;i<m;++i){
			if(t1[i]!=t2[i])L=min(L,i),R=max(R,i);
		}
		H[0][0]=t1[0]-'a';
		for(register int i=1;i<m;++i)H[i][0]=H[i-1][0]*B+t1[i]-'a';
		H[0][1]=t2[0]-'a';
		for(register int i=1;i<m;++i)H[i][1]=H[i-1][1]*B+t2[i]-'a';
		int len=R-L+1,ans=0;
		int i=lower_bound(a,a+n,len)-a;
		for(;i<n;++i){
//			++cnt;
			int l=L+len-a[i],r=L;
			if(l+a[i]>m)break;
			if(a[i]>m)break;
			for(register int j=max(l,0ll);j<=r and j+a[i]<=m;++j){
				++cnt;
				bool flag=true;
				ull num1=h[i][0];
				ull num2=h[i][1]; 
				ull Num1=H[j+a[i]-1][0]-(j?H[j-1][0]:0)*qB[a[i]];
				ull Num2=H[j+a[i]-1][1]-(j?H[j-1][1]:0)*qB[a[i]];
				if(num1!=Num1)flag=false;
				if(num2!=Num2)flag=false;
				if(flag)++ans;
			}
//			if(!F)cerr<<l<<" "<<r<<'\n';
		}
		cout<<ans<<'\n';
	}
//	cerr<<cnt<<'\n';
	return 0;
}

