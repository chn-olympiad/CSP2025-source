#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e6+5;
ll n,q,ans;

string ss1,ss2,s1[N],s2[N];
string a,b,at,bt;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ss1>>ss2;
		ll lens=ss1.length();
		for(int j=0;j<lens;j++){
			if(ss1[j]!=ss2[j]){
				s1[i]+=ss1[j];
				s2[i]+=ss2[j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		at="";
		bt="";
		ans=0;
		int lsa=a.length();
		int lsb=b.length();
		if(lsa!=lsb){
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<lsa;j++){
			if(a[j]!=b[j]){
				at+=a[j];
				bt+=b[j];
			}
		}
		for(int j=1;j<=n;j++){
			if(at==s1[j]&&bt==s2[j]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}