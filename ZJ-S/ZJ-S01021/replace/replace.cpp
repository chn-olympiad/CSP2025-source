#include<bits/stdc++.h>
using namespace std;

const long long N=2e5+10;
long long n,q;
long long l[N];
long long r[N];
unsigned long long h[N];
unsigned long long h2[N];
unsigned long long h3[N];
string s[N][2];
string t[2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		long long len=s[i][0].size();
		s[i][0]=' '+s[i][0];
		s[i][1]=' '+s[i][1];
		for(long long j=1;j<=len;j++){
			if(l[i]==0&&s[i][0][j]!=s[i][1][j])l[i]=j;
			if(s[i][0][j]!=s[i][1][j])r[i]=max(r[i],j);
		}
		for(long long j=l[i];j<=r[i];j++)
			h[i]=h[i]*29+(s[i][0][j]-'a');
		for(long long j=l[i];j<=r[i];j++)
			h[i]=h[i]*29+(s[i][1][j]-'a');
		for(long long j=1;j<l[i];j++)h2[i]=h2[i]*29+(s[i][0][j]-'a');
		for(long long j=r[i]+1;j<=len;j++)h3[i]+=h3[i]*29+(s[i][0][j]-'a');
		r[i]=len-r[i];
//		cout<<h[i]<<' '<<h2[i]<<' '<<h3[i]<<' '<<l[i]<<' '<<r[i]<<endl;
	}
//	cout<<endl;
	while(q--){
		long long ans=0;
		cin>>t[0]>>t[1];
		long long len=t[0].size();
		t[0]=' '+t[0];
		t[1]=' '+t[1];
		long long l2=0,r2=0;
		unsigned long long H=0,H2=0,H3=0; 
		for(long long j=1;j<=len;j++){
			if(l2==0&&t[0][j]!=t[1][j])l2=j;
			if(t[0][j]!=t[1][j])r2=max(r2,j);
		}
		for(long long j=l2;j<=r2;j++)
			H=H*29+(t[0][j]-'a');
		for(long long j=l2;j<=r2;j++)
			H=H*29+(t[1][j]-'a');
		for(int i=1;i<=n;i++){
			if(H==h[i]){
				H2=H3=0;
//				cout<<i<<' ';
//				cout<<l2-l[i]+1<<' '<<l2-1<<endl;
				if(l2-l[i]+1<=0)continue;
				for(long long j=l2-l[i]+1;j<l2;j++)H2=H2*29+(t[0][j]-'a');
//				cout<<H2<<endl;
				if(H2!=h2[i])continue;
//				cout<<r2+1<<' '<<r2+r[i]<<endl;
				if(r2+r[i]>len)continue;
				for(long long j=r2+1;j<=r2+r[i];j++)H3+=H3*29+(t[0][j]-'a');	
//				cout<<H3<<"\n\n";
				if(H3!=h3[i])continue;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

