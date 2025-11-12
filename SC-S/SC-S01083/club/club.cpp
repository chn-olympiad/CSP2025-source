#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,k;
long long ans;
struct student{
	int p,q,r,less;
	int best;
}s[100010];
bool cmp(student aa,student bb){
	return aa.less<bb.less;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		k=n/2,ans=0,a=0,b=0,c=0;
		for(int j=0;j<n;j++){
			cin>>s[j].p>>s[j].q>>s[j].r;
			if(s[j].p>=s[j].q and s[j].p>=s[j].r){
				s[j].best=1,a++,ans+=s[j].p;
				s[j].less=s[j].p-max(s[j].q,s[j].r);
			}
			else if(s[j].q>=s[j].p and s[j].q>=s[j].r){
				s[j].best=2,b++,ans+=s[j].q;
				s[j].less=s[j].q-max(s[j].p,s[j].r);
			}
			else if(s[j].r>=s[j].q and s[j].r>=s[j].p){
				s[j].best=3,c++,ans+=s[j].r;
				s[j].less=s[j].r-max(s[j].q,s[j].p);
			}
		}
		sort(s,s+n,cmp);
		int yy=0;
		while(a>k){
			if(s[yy].best==1)
				ans-=s[yy].less,a--;
			yy++;
		}
		yy=0;
		while(b>k){
			if(s[yy].best==2)
				ans-=s[yy].less,b--;
			yy++;
		}
		yy=0;
		while(c>k){
			if(s[yy].best==3)
				ans-=s[yy].less,c--;
			yy++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}