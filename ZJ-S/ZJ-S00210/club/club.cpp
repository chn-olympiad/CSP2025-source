#include <bits/stdc++.h>
using namespace std;
int  T,n,i,j,m,dp[100010],a[100010][4],beibao1,beibao2,beibao3,ma;
int t1,t2,t3,o,o1,o2,t;
int ans,ma1,ma2,ma3,ren,rs,like[100010],like2[100010],like3[100010];
struct no{
	int x,id;
}bm1[100010],bm2[100010],bm3[100010];
bool cmp(no q,no h){
	return q.x<h.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==2){
			ma=0;
			int sh,sh1,sh2,li2,li3,li;
			cin>>sh>>sh1>>sh2>>li>>li2>>li3;
			ma=max(sh+li2,max(sh+li3,max(sh1+li,max(sh1+li3,max(sh2+li,sh2+li2)))));
			cout<<ma<<endl;
		}
		else{
			ans=0;t1=t2=t2=0;
			for(i=1;i<=n;i++){
				ma1=ma2=0;
				for(j=1;j<=3;j++) {
					cin>>a[i][j];
					if(ma1<a[i][j]) ma1=a[i][j],like3[i]=like2[i],like2[i]=like[i],like[i]=j;
					else if(ma2<a[i][j]) ma2=a[i][j],like3[i]=like2[i],like2[i]=j;
					else like3[i]=j;
				}
			}
			rs=n/2;
			for(i=1;i<=n;i++){
				if(like[i]==1) bm1[++t1].id=i,bm1[t1].x=a[i][1];	
				if(like[i]==2) bm2[++t2].id=i,bm2[t2].x=a[i][2];
				if(like[i]==3) bm3[++t3].id=i,bm3[t3].x=a[i][3];	
			}
			o=o1=o2=1;
			sort(bm1+1,bm1+1+t1,cmp);
			sort(bm2+1,bm2+1+t2,cmp);
			sort(bm3+1,bm3+1+t3,cmp);
			while(t1-o+1>rs){
				t=bm1[o].id;
					if(like2[t]==2){
					if(t2<rs) bm2[++t2].id=i,bm2[t2].x=a[t][2]; 
					else bm3[++t3].id=i,bm3[t3].x=a[t][3];
					}
				else{
					if(t3<rs) bm3[++t3].id=i,bm3[t3].x=a[t][3]; 
					else bm2[++t2].id=i,bm2[t2].x=a[t][2]; 
				}
				o++;
			}
			while(t2-o1+1>rs){
				t=bm2[o1].id;
				if(like2[t]==1){
					if(t1<rs) bm1[++t1].id=i,bm1[t1].x=a[t][1]; 
					else bm3[++t3].id=i,bm3[t3].x=a[t][3];
				}
				else{
					if(t3<rs) bm3[++t3].id=i,bm3[t3].x=a[t][3]; 
					else bm1[++t1].id=i,bm1[t1].x=a[t][1];
				}
				o1++;
			}
			while(t3-o2+1>rs){
				t=bm3[o2].id;
				if(like2[t]==1){
					if(t1<rs) bm1[++t1].id=i,bm1[t1].x=a[t][1]; 
					else bm2[++t2].id=i,bm2[t2].x=a[t][2]; 
				}
				else{
					if(t2<rs) bm2[++t2].id=i,bm2[t2].x=a[t][2]; 
					else bm1[++t1].id=i,bm1[t1].x=a[t][1];
				}
				o2++;
			}
			for(i=o;i<=t1;i++) ans+=bm1[i].x;
			for(i=o1;i<=t2;i++) ans+=bm2[i].x;
			for(i=o2;i<=t3;i++) ans+=bm3[i].x;
			memset(bm1,0,sizeof(bm1));
			memset(bm2,0,sizeof(bm2));
			memset(bm3,0,sizeof(bm3));
			cout<<ans<<endl;
		}
	}
	return 0;
}
