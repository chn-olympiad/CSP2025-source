#include<bits/stdc++.h>
using namespace std;
struct sa{
	int a,b,c,fst,snd,da,frd;
}sat[100005];
int a[100005],b[100005],c[100005],acnt,bcnt,ccnt;
using namespace std ;
bool f(int x,int y){
	return sat[x].da>sat[y].da;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	long long ans;
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		acnt=0;bcnt=0;ccnt=0;
		ans=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>sat[j].a>>sat[j].b>>sat[j].c;
			int t=max(max(sat[j].a,sat[j].b),sat[j].c);
			if(sat[j].a==t){
				sat[j].fst=1;
				sat[j].frd=sat[j].a;
				int l=max(sat[j].b,sat[j].c);
				if(sat[j].b==l)sat[j].snd=2;
				else sat[j].snd=3;
				sat[j].da=t-l;
			}
			else if(sat[j].b==t){
				sat[j].fst=2;
				sat[j].frd=sat[j].b;
				int l=max(sat[j].a,sat[j].c);
				if(sat[j].a==l)sat[j].snd=1;
				else sat[j].snd=3;
				sat[j].da=t-l;
			}
			else{
				sat[j].frd=sat[j].c;
				sat[j].fst=3;
				int l=max(sat[j].a,sat[j].b);
				if(sat[j].a==l)sat[j].snd=1;
				else sat[j].snd=2;
				sat[j].da=t-l;
			}
		}
		for(int j=1;j<=n;j++){
			if(sat[j].fst==1){
				ans+=sat[j].a;
				if(acnt<n/2){
					a[++acnt]=j;
				}
				else {
					sort(a+1,a+acnt+1,f);
					if(sat[j].da>sat[a[acnt]].da){
						ans-=sat[a[acnt]].da;
						a[acnt]=j;
					}
					else ans-=sat[j].da;
				}
			}
			if(sat[j].fst==2){
				ans+=sat[j].b;
				if(bcnt<n/2){
					b[++bcnt]=j;
				}
				else {
					sort(b+1,b+bcnt+1,f);
					if(sat[j].da>sat[b[bcnt]].da){
						ans-=sat[b[bcnt]].da;
						b[bcnt]=j;
					}
					else ans-=sat[j].da;
				}
			}
			if(sat[j].fst==3){
				ans+=sat[j].c;
				if(ccnt<n/2){
					c[++ccnt]=j;
				}
				else {
					sort(c+1,c+ccnt+1,f);
					if(sat[j].da>sat[c[ccnt]].da){
						ans-=sat[c[ccnt]].da;
						c[ccnt]=j;
					}
					else ans-=sat[j].da;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
}