#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull MOD=1000000007;
int n,q;
struct inm{
	int ls;
	string at,bt;
}s[200001];
ull jz[5000001];
string a,b;
bool cmp(inm i,inm j){
	return i.ls<j.ls;
}
ull hb,ha[5000001];
bool check(string pa,string pb){
	int lpa=pa.size(),lpb=pb.size();
	if(lpb>lpa)return 0;
//	cout<<pa<<" "<<pb<<"\n";
	hb=0;
	for(int i=0;i<lpb;i++){
		hb=hb*MOD+pb[i]-'a';
	}
//	cout<<hb<<"\n";
	ha[0]=pa[0]-'a';
//	cout<<ha[0]<<"\n";
	for(int i=1;i<lpa;i++){
		ha[i]=ha[i-1]*MOD+pa[i]-'a';
		if(i>=lpb){
			if(ha[i]-ha[i-lpb]*jz[lpb]==hb)return 1;
		}
//		cout<<ha[i]<<" "<<ha[i]-ha[i-lpb]*jz[lpb]<<"\n";
	}
	if(ha[lpb-1]==hb)return 1;
//	cout<<"----\n";
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i].at>>s[i].bt;
		s[i].ls=s[i].at.size();
	}
	jz[0]=1;
	for(int i=1;i<=5000000;i++){
		jz[i]=jz[i-1]*MOD;
	}
	sort(s+1,s+1+n,cmp);
	while(q--){
		int ans=0;
		cin>>a>>b;
		if(a.size()!=b.size()){
			printf("0\n");
			continue;
		}
		int la=a.size();int l=la,r=0;
		for(int i=0;i<la;i++){
			if(a[i]!=b[i]){
				l=min(l,i);r=max(r,i);
			}
		}
		string ca="",cb="";
		int lc=r-l+1;
		while(l<=r){
			ca=ca+a[l];cb=cb+b[l];
			l++;
		}
		for(int i=1;i<=n;i++){
			if(check(a,s[i].at)&&check(b,s[i].bt)&&check(s[i].at,ca)&&check(s[i].bt,cb))ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}