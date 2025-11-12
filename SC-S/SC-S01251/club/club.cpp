#include<bits/stdc++.h>
using namespace std;
long long t,n,jb,jc,ans;
struct a{
	long long da,db,dc,c;
}s[101010];
bool cmpa(a x,a y){
	return x.da>=y.da;
}
bool cmpb(a x,a y){
	return x.db>=y.db;
}
bool cmpc(a x,a y){
	return x.dc>=y.dc;
}
bool cmpt(a x,a y){
	return x.c>=y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int x=1;x<=t;x++){
		n=0;jb=0;jc=0;ans=0;
		memset(s,0,sizeof(s));
		cin>>n;
		for(int i=1;i<=n;i++){	
			cin>>s[i].da>>s[i].db>>s[i].dc;
			if(s[i].db)jb=1;
			if(s[i].dc)jc=1;
			s[i].c=s[i].da-s[i].db;
		}
		if(jb==0&&jc==0){
			sort(s+1,s+n+1,cmpa);
			for(int i=1;i<=n/2;i++){
				ans+=s[i].da;
			}
			cout<<ans;
		}
		if(jb!=0&&jc==0){
			sort(s+1,s+n+1,cmpt);
			for(int i=1;i<=n/2;i++){
				ans+=s[i].da;
			}
			for(int i=n/2;i<=n;i++){
				ans+=s[i].db;
			}
			cout<<ans;
		}
	}
	return 0;
}