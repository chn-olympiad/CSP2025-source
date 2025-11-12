#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
struct maxj{
	int idj=0,id=0,cnt=0,ab=0,cha=0,cid=0;
};
int a[100001][4],p[4];maxj b1[100001],b2[100001],b3[100001];
bool cmp(maxj x,maxj y){
	return x.cnt>y.cnt;
}
bool cmpe(maxj x,maxj y){
	return x.ab>y.ab;
}
bool cmpj(maxj x,maxj y){
	return x.cha>y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;int tp=n/2;
		p[1]=p[2]=p[3]=0;bool A=true,B=true;
		for(int i=1;i<=n;i++){
			maxj maxx,minn,cent;minn.cnt=1e9;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2&&a[i][j]!=0) A=false;
				if(j==3&&a[i][j]!=0) A=false,B=false;
				if(a[i][j]>maxx.cnt){
					maxx.cnt=a[i][j];
					maxx.idj=j;maxx.id=i;
				}
				if(a[i][j]<minn.cnt){
					minn.cnt=a[i][j];
					minn.idj=j;minn.id=i;
				}
			}
			for(int j=1;j<=3;j++){
				if(j!=maxx.idj&&j!=minn.idj){
					cent.cnt=a[i][j];
					cent.idj=j;cent.id=i;
				}
			}
			maxx.ab=a[i][1]-a[i][2];
			if(maxx.idj==1) b1[++p[1]]=maxx,b1[p[1]].ab=abs(maxx.ab),b1[p[1]].cid=cent.id,b1[p[1]].cha=maxx.cnt-cent.cnt;
			else if(maxx.idj==2) b2[++p[2]]=maxx,b2[p[2]].ab=abs(maxx.ab),b2[p[2]].cid=cent.id,b2[p[2]].cha=maxx.cnt-cent.cnt;
			else if(maxx.idj==3) b3[++p[3]]=maxx,b3[p[3]].ab=abs(maxx.ab),b3[p[3]].cid=cent.id,b3[p[3]].cha=maxx.cnt-cent.cnt;
		}
		if(A){
			sort(b1+1,b1+p[1]+1,cmp);
			for(int i=1;i<=tp;i++){
				ans+=b1[i].cnt;
			}
		}else if(B){
			if(p[1]>tp){
				sort(b1+1,b1+p[1]+1,cmpe);
				for(;p[1]>tp;p[1]--){
					b2[++p[2]].cnt=a[b1[p[1]].id][2];
				}
			}else if(p[2]>tp){
				sort(b2+1,b2+p[2]+1,cmpe);
				for(;p[2]>tp;p[2]--){
					b1[++p[1]].cnt=a[b2[p[2]].id][1];
				}
			}
			for(int i=1;i<=p[1];i++){
				ans+=b1[i].cnt;
			}
			for(int i=1;i<=p[2];i++){
				ans+=b2[i].cnt;
			}
		}else{
			if(p[1]>tp){
				sort(b1+1,b1+p[1]+1,cmpj);
				for(;p[1]>tp;p[1]--){
					if(b1[p[1]].cid==2) b2[++p[2]]=b1[p[1]],b2[p[2]].cnt-=b2[p[2]].cha;
					else b3[++p[3]]=b1[p[1]],b3[p[3]].cnt-=b3[p[3]].cha;
				}
			}else if(p[2]>tp){
				sort(b2+1,b2+p[2]+1,cmpj);
				for(;p[2]>tp;p[2]--){
					if(b1[p[1]].cid==1) b1[++p[1]]=b2[p[2]],b1[p[1]].cnt-=b1[p[1]].cha;
					else b3[++p[3]]=b2[p[2]],b3[p[3]].cnt-=b3[p[3]].cha;
				}
			}else if(p[3]>tp){
				sort(b3+1,b3+p[3]+1,cmpj);
				for(;p[3]>tp;p[3]--){
					if(b1[p[1]].cid==1) b1[++p[1]]=b3[p[3]],b1[p[1]].cnt-=b1[p[1]].cha;
					else b2[++p[2]]=b3[p[3]],b2[p[2]].cnt-=b2[p[2]].cha;
				}
			}
			for(int i=1;i<=p[1];i++){
				ans+=b1[i].cnt;
			}
			for(int i=1;i<=p[2];i++){
				ans+=b2[i].cnt;
			}
			for(int i=1;i<=p[3];i++){
				ans+=b3[i].cnt;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}