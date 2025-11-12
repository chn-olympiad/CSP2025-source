#include<bits/stdc++.h>
using namespace std;
int t,n;
struct student{
	int a,b,c;
}s[100005];
struct p{
	int score,pos;
}s2[4];
bool cmpn(p g,p h){
	return g.score>h.score;
}
bool cmp(student g,student h){
	if(g.a!=h.a) return g.a>h.a;
	else if(g.a==h.a&&g.b!=h.b) return g.b>h.b;
	else return g.c>h.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++) cin>>s[j].a>>s[j].b>>s[j].c;
		int d[]={0,0,0,0},ans=0;
		sort(s+1,s+n+1,cmp);
		for(int j=1;j<=n;j++){
			int x=s[j].a,y=s[j].b,z=s[j].c;
			s2[1].score=x; s2[1].pos=1;
			s2[2].score=y; s2[2].pos=2;
			s2[3].score=z; s2[3].pos=3;
			sort(s2+1,s2+3+1,cmpn);
			if(d[s2[1].pos]+1<=(n/2)){
				d[s2[1].pos]++;
				ans+=s2[1].score;
			}
			else if(d[s2[2].pos]<=n/2){
				d[s2[2].pos]++;
				ans+=s2[2].score;
			}
			else{
				d[s2[3].pos]++;
				ans+=s2[3].score;
			}
		}
		cout<<ans;
	}
	return 0;
}
