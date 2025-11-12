#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
const int N=2e5+5;
ull t[N][2],sum1[2005],sum2[2005],M[2005];
int slen[N];
ull getsum(int l,int r){
	return sum1[r]-sum1[l-1]*M[r-l+1];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		int len=s.size();
		slen[i]=len;
		for(int j=0;j<len;j++) t[i][0]=t[i][0]*7+s[j];
		cin>>s;
		len=s.size();
		for(int j=0;j<len;j++) t[i][1]=t[i][1]*7+s[j];
	}
	M[0]=1;
	for(int i=1;i<=2000;i++) M[i]=M[i-1]*7;
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size();
		s1=' '+s1,s2=' '+s2;
		int ans=0;
		for(int i=1;i<=len;i++) sum1[i]=sum1[i-1]*7+s1[i];
		for(int i=1;i<=len;i++) sum2[i]=sum2[i-1]*7+s2[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j+slen[i]-1<=len;j++){
				if(sum1[j+slen[i]-1]-sum1[j-1]*M[slen[i]]==t[i][0]){
					ull h1=sum1[j-1];
					ull h2=t[i][1];
					ull h3=getsum(j+slen[i],len);
					if(h3+h2*M[len-j-slen[i]+1]+h1*M[len-j+1]==sum2[len]) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
