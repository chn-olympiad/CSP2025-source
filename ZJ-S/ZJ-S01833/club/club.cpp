#include<bits/stdc++.h>
using namespace std;
int T;
int n,k;
struct club{
	int a,b,c;
	int m,n;
	bool x,y,z;
}s[100010];
int sa,sb,sc;
int ans;
bool sorta(club l,club r){
	if(l.x&&r.x) return l.m-l.n>r.m-r.n;
	return l.x>r.x;
}
bool sortb(club l,club r){
	if(l.y&&r.y) return l.m-l.n>r.m-r.n;
	return l.y>r.y;
	
}
bool sortc(club l,club r){
	if(l.z&&r.z) return l.m-l.n>r.m-r.n;
	return l.z>r.z;
	
}
void solve(){
	ans=0,sa=0,sb=0,sc=0;
	cin>>n;
	k=n/2;
	for(int i=1;i<=n;i++){
		s[i].x=false,s[i].y=false,s[i].z=false;
		int tmp=0;
		cin>>s[i].a>>s[i].b>>s[i].c;
		s[i].m=max(s[i].a,max(s[i].b,s[i].c));
		if(s[i].m==s[i].a){
			tmp++;
			s[i].x=true;
		}
		if(s[i].m==s[i].b){
			tmp++;
			s[i].y=true;
		}
		if(s[i].m==s[i].c){
			tmp++;
			s[i].z=true;
		}
		if(tmp>1){
			ans+=s[i].m;
			i--;
			n--;
		}else{
			if(s[i].x==true){
				sa++;
				s[i].n=max(s[i].b,s[i].c);
			}else if(s[i].y==true){
				sb++;
				s[i].n=max(s[i].a,s[i].c);
			}else{
				sc++;
				s[i].n=max(s[i].a,s[i].b);
			}
		}
	} 
	if(sa<=k&&sb<=k&&sc<=k){
		for(int i=1;i<=n;i++)
			ans+=s[i].m;
	}else if(sa>k){
		sort(s+1,s+n+1,sorta);
		for(int i=1;i<=k;i++){
			ans+=s[i].m;
		} 
		for(int i=k+1;i<=n;i++){
			if(s[i].x) ans+=s[i].n;
			else ans+=s[i].m;
		}
	}else if(sb>k){
		sort(s+1,s+n+1,sortb);
		for(int i=1;i<=k;i++) ans+=s[i].m;
		for(int i=k+1;i<=n;i++){
			if(s[i].y) ans+=s[i].n;
			else ans+=s[i].m;
		}
	}else{
		sort(s+1,s+n+1,sortc);
		for(int i=1;i<=k;i++){
			ans+=s[i].m;
		} 
		for(int i=k+1;i<=n;i++){
			if(s[i].z){
				ans+=s[i].n;
			} 
			else{
				ans+=s[i].m;
			} 
		}
	}
	cout<<ans<<'\n';
	
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}
