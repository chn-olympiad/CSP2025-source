#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int maxn=1e5+10;
typedef pair<int,int>PII;
struct node{
	int a,b,c;
	bool vis;
}w[maxn];
int ans,ans1,ans2,ans3;
int cnt1,cnt2,cnt3;
int n,m;
inline void init(){
	ans=ans1=ans2=ans3=0;
	cnt1=cnt2=cnt3=0;
}
inline bool cmp1(node x,node y){
	return x.a>y.a;
}
inline bool cmp2(node x,node y){
	return x.b>y.b;
}
inline bool cmp3(node x,node y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
    	init();
	    scanf("%d",&n);
	    m=n/2;
	    for(int i=1;i<=n;i++){
	    	int x,y,z;
	    	scanf("%d%d%d",&x,&y,&z);
	    	w[i].a=x;
	    	w[i].b=y;
	    	w[i].c=z;
	    	w[i].vis=0;
		}
		sort(w+1,w+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(cnt1>=m){
				break;
			}
			ans1+=w[i].a;
			w[i].vis=true;
			cnt1++;
		}
		sort(w+1,w+1+n,cmp2);
		for(int i=1;i<=n;i++){
			if(cnt2>=m){
				break;
			}
			if(w[i].vis){
				if(w[i].b>w[i].a){
					cnt1--;cnt2++;
					ans2+=w[i].b;
					ans1-=w[i].a;
				}else{
					continue;
				}
			}else{
				cnt2++;
				ans2+=w[i].b;
				w[i].vis=1;
			}
		}
		sort(w+1,w+1+n,cmp3);
		for(int i=1;i<=n;i++){
			if(cnt3>=m){
				break;
			}
			if(w[i].vis){
				if(w[i].c>w[i].a){
					cnt1--;cnt3++;
					ans3+=w[i].c;
					ans1-=w[i].a;
				}else if(w[i].c>w[i].b){
					cnt2--;cnt3++;
					ans3+=w[i].c;
					ans2-=w[i].b;
				}else{
					continue;
				}
			}else{
				ans3+=w[i].c;
				cnt3++;
				w[i].vis=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(!w[i].vis){
				int *p=NULL;
				node t=w[i];
				int x=t.a,y=t.b,z=t.c;
				int va=m-cnt1,vb=m-cnt2,vc=m-cnt3;
				if(x>y&&x>z){
					p=&x;
				}else if(y>x&&y>z){
					p=&y;
				}else if(z>x&&z>y){
					p=&z;
				}
				if(p==&x&&cnt1<m){
					cnt1++;
					ans1+=*p;
				}else if(p==&y&&cnt2<m){
					cnt2++;
					ans2+=*p;
				}else if(p==&z&&cnt3<m){
					cnt3++;
					ans3+=*p;
				}
			}
		}
		ans=ans1+ans2+ans3;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
