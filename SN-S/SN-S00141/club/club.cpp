#include<bits/stdc++.h>
using namespace std;
long long t,n,m;
long long ax,bx,cx,ay[200001],by[200001],cy[200001];
struct ss{
	long long x,y,w;
}a[4];
ss sa[4];
struct dd{
	long long x,x2,x3,y,y2,y3,fwei;
}s[200001];
long long k;
bool cmp(ss x,ss y){
	return x.x>y.x;
}
bool cmp1(ss x,ss y){
	return x.w>y.w;
}
void sas(){
	ax=0;bx=0;cx=0;k=0;
	for(int i=1;i<=n;i++){
		s[i].x=0;
		s[i].y=0;
		s[i].x2=0;
		s[i].y2=0;
		s[i].x3=0;
		s[i].y3=0;
		ay[i]=0;
		by[i]=0;
		cy[i]=0;
		s[i].fwei=0;
	}
	for(int i=1;i<=3;i++){
		a[i].x=0;
		a[i].y=0;
		a[i].w=0;
		sa[i].x=0;
		sa[i].y=0;
		sa[i].w=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[1].x>>a[2].x>>a[3].x;
			a[1].y=1;
			a[2].y=2;
			a[3].y=3;
			sort(a+1,a+4,cmp);
			s[i].x=a[1].x;
			s[i].y=a[1].y;
			s[i].x2=a[2].x;
			s[i].y2=a[2].y;
			s[i].x3=a[3].x;
			s[i].y3=a[3].y;
		}
		int o=n/2;
		sa[1].y=1;
		sa[2].y=2;
		sa[3].y=3;
		for(int i=1;i<=n;i++){
			if(s[i].y==1) {
				sa[1].w++;
				ay[sa[1].w]=i;
				sa[1].x+=s[i].x;
			}
			else if(s[i].y==2) {
				sa[2].w++;
				by[sa[2].w]=i;
				sa[2].x+=s[i].x;
			}
			else if(s[i].y==3) {
				sa[3].w++;
				cy[sa[3].w]=i;
				sa[3].x+=s[i].x;
			}
		}
		
		
		sort(sa+1,sa+1+3,cmp1);
		if(sa[1].w>o){
			ss p[sa[1].w+1];
			sa[2].w=sa[1].w-o;
			for(int j=1;j<=sa[1].w;j++){
				if(sa[1].y==1) {
					p[j].x=s[ay[j]].x-s[ay[j]].x2;
					p[j].y=j;
				}
				if(sa[1].y==2) {
					p[j].x=s[by[j]].x-s[by[j]].x2;
					p[j].y=j;
				}
				if(sa[1].y==3) {
					p[j].x=s[cy[j]].x-s[cy[j]].x2;
					p[j].y=j;
				}
			}
				sort(p+1,p+1+sa[1].w,cmp);
				for(int k=sa[1].w;k>o;k--){
					if(sa[1].y==1){
						sa[1].x-=s[ay[p[k].y]].x;
						s[ay[p[k].y]].fwei=1;
						if(sa[2].y==2) sa[2].x+=s[ay[p[k].y]].x2;
						if(sa[2].y==3) sa[2].x+=s[ay[p[k].y]].x2;
					}
					if(sa[1].y==2){
						sa[1].x-=s[by[p[k].y]].x;
						s[ay[p[k].y]].fwei=1;
						if(sa[2].y==1) sa[2].x+=s[by[p[k].y]].x2;
						if(sa[2].y==3) sa[2].x+=s[by[p[k].y]].x2;
					}
					if(sa[1].y==3){
						sa[1].x-=s[cy[p[k].y]].x;
						s[ay[p[k].y]].fwei=1;
						if(sa[2].y==1) sa[2].x+=s[cy[p[k].y]].x2;
						if(sa[2].y==2) sa[2].x+=s[cy[p[k].y]].x2;
					}
				}
		}
		
		
		
		
		if(sa[2].w>o){
			ss p[sa[2].w+1];
			sa[3].w=sa[2].w-o;
			for(int j=1;j<=sa[2].w;j++){
				if(sa[2].y==1 &&s[ay[j]].fwei==1){
					p[j].x=s[ay[j]].x2-s[ay[j]].x3;
					
				}
				else if(sa[2].y==2&&s[by[j]].fwei==1) {
					p[j].x=s[by[j]].x2-s[by[j]].x3;
				}
				else if(sa[2].y==3&&s[cy[j]].fwei==1) {
					p[j].x=s[cy[j]].x2-s[cy[j]].x3;
				}
				else if(sa[2].y==1) {
					p[j].x=s[ay[j]].x-s[ay[j]].x2;
					p[j].y=j;
				}
				else if(sa[2].y==2) {
					p[j].x=s[by[j]].x-s[by[j]].x2;
					p[j].y=j;
				}
				else if(sa[2].y==3) {
					p[j].x=s[cy[j]].x-s[cy[j]].x2;
					p[j].y=j;
				}
			}
				sort(p+1,p+1+sa[2].w,cmp);
				for(int k=sa[2].w;k>o;k--){
					if(sa[2].y==1&&s[ay[p[k].y]].fwei==1){
						sa[2].x-=s[ay[p[k].y]].x2;
						if(sa[3].y==2) sa[3].x+=s[ay[p[k].y]].x3;
						if(sa[3].y==3) sa[3].x+=s[ay[p[k].y]].x3;
					}
					if(sa[2].y==2&&s[by[p[k].y]].fwei==1){
						sa[2].x-=s[by[p[k].y]].x2;
						if(sa[3].y==1) sa[3].x+=s[by[p[k].y]].x3;
						if(sa[3].y==3) sa[3].x+=s[by[p[k].y]].x3;
					}
					if(sa[2].y==3&&s[cy[p[k].y]].fwei==1){
						sa[2].x-=s[cy[p[k].y]].x2;
						if(sa[3].y==1) sa[3].x+=s[cy[p[k].y]].x3;
						if(sa[3].y==2) sa[3].x+=s[cy[p[k].y]].x3;
					}
					if(sa[2].y==1){
						sa[2].x-=s[ay[p[k].y]].x;
						if(sa[3].y==2) sa[3].x+=s[ay[p[k].y]].x2;
						if(sa[3].y==3) sa[3].x+=s[ay[p[k].y]].x2;
					} 
					if(sa[2].y==2){
						sa[2].x-=s[by[p[k].y]].x;
						if(sa[3].y==1) sa[3].x+=s[by[p[k].y]].x2;
						if(sa[3].y==3) sa[3].x+=s[by[p[k].y]].x2;
					}
					if(sa[2].y==3){
						sa[2].x-=s[cy[p[k].y]].x;
						if(sa[3].y==1) sa[3].x+=s[cy[p[k].y]].x2;
						if(sa[3].y==2) sa[3].x+=s[cy[p[k].y]].x2;
					}
				}
		}
		cout<<abs(sa[3].x)+abs(sa[2].x)+abs(sa[1].x)<<endl;
		sas();
	}
	
}
