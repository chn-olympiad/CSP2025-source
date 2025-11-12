#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pr pair<long long,long long>
#define forr(i,n) for(long long i=1;(i)<=(n);i++)
#define fo(i,n) for(long long i=0;(i)<(n);i++)
#define gc getchar
#define pc putchar
ll num,numm[110],f,cnt;
char cc;
ll n,q,ff=1,a[200010],to,tt,ans,fff;
pr b[200010];
string s[200010][5],t[5];
ll in(){
	f=1,num=0,cc=gc();
	for(;cc>'9'||cc<'0';cc=gc())
		if(cc=='-')
			f=-1;
	for(;cc<='9'&&cc>='0';cc=gc())
		num=num*10+cc-'0';
	return num*f;
}
void out(ll x){
	cnt=0,f=1;
	if(x==0)
		pc('0');
	else{
		if(x<0)
			x=-x,f=-1;
		while(x)
			numm[++cnt]=x%10,x/=10;
		for(ll i=cnt;i>=1;i--)
			pc(numm[i]+'0');
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=in(),q=in();
	fff=0;
	forr(i,n){
		cin>>s[i][1]>>s[i][2];
		fo(j,s[i][1].size()){
			if(s[i][2][j]!=s[i][1][j])
				fff=1;
			if(fff)
				s[i][3]+=s[i][2][j]-s[i][1][j];
			if(s[i][1][j]=='b')
				b[i].first=j;
			if(s[i][2][j]=='b')
				b[i].second=j;
			if((s[i][1][j]!='a'&&s[i][1][j]!='b')||(s[i][2][j]!='a'&&s[i][2][j]!='b'))
				ff=0;
		}
	}
	if(ff){
		while(q--){
			ans=0;
			cin>>t[1]>>t[2];
			if(t[1].size()!=t[2].size()){
				pc(0);
				pc('\n');
			}
			else{
				fo(i,t[1].size()){
					if(t[1][i]=='b')
						to=i;
					if(t[2][i]=='b')
						tt=i;
				}
				forr(i,n)
					if(tt-to==b[i].second-b[i].first&&to>=b[i].first&&tt>=b[i].second&&(t[1].size()-s[i][1].size()>=to-b[i].first))
						ans++;
				out(ans);
				pc('\n');
			}
		}
	}
	else{
		while(q--){
			ans=0,fff=0;
			cin>>t[1]>>t[2];
			if(t[1].size()!=t[2].size())
				pc(0);
			else{
				fo(i,t[1].size()){
					if(t[2][i]!=t[1][i])
						fff=1;
					if(fff)
						t[3]+=t[2][i]-t[1][i];
				}
				forr(i,n){
					t[4]=t[3];
					while(s[i][3].size()<t[3].size())
						s[i][3]+='0'-'0';
					if(s[i][3]==t[3])
						ans++;
				}
				out(ans);
				pc('\n');
			}
		}
	}
	return 0;
}