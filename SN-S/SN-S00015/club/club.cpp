#include<bits/stdc++.h>
using namespace std;
long long n,a[100007][10],t,ans,aaa,bbb,ccc,ls,dd[100007];
bool tf[100007];
struct cs{
	long long sum,num;
};
cs aa[100007],bb[100007],cc[100007],xx[100007],yy[100007],zz[100007];
bool cmp(cs x,cs y){
	return x.sum>y.sum;
}
bool cmp2(long long x,long long y){
	return x<y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		ans=0,aaa=0,bbb=0,ccc=0,ls=0;
		cin>>n;
		memset(tf,sizeof(tf),0),memset(dd,sizeof(dd),0),memset(a,sizeof(a),0);
		memset(xx,sizeof(xx),0),memset(yy,sizeof(yy),0),memset(zz,sizeof(zz),0);
		memset(aa,sizeof(aa),0),memset(bb,sizeof(bb),0),memset(cc,sizeof(cc),0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
//				if(t==3){
//					cout<<a[i][j]<<' ';
//				}
			}
			aa[i].sum=a[i][1],aa[i].num=i;
			bb[i].sum=a[i][2],bb[i].num=i;
			cc[i].sum=a[i][3],cc[i].num=i;
		}
		sort(aa+1,aa+n+1,cmp);
		sort(bb+1,bb+n+1,cmp);
		sort(cc+1,cc+n+1,cmp);
		for(int i=1;i<=n;i++){
			ans+=aa[i].sum;
			tf[aa[i].num]=1;
			aaa++;
		}
		for(int i=1;i<=n;i++){
			if(!tf[i]){
				ans+=bb[i].sum;
				tf[bb[i].num]=1;
				bbb++;
			}else if(a[bb[i].num][1]<a[bb[i].num][2]){
				ans=ans-a[bb[i].num][1]+a[bb[i].num][2];
				aaa--,bbb++;
			}
		}
		for(int i=1;i<=n;i++){
			if(!tf[i]){
				ans+=cc[i].sum;
				tf[cc[i].num]=1;
				ccc++;
			}else if(a[cc[i].num][1]<a[cc[i].num][2]&&a[cc[i].num][2]<a[cc[i].num][3]){
				bbb--,ccc++,ans=ans-a[cc[i].num][2]+a[cc[i].num][3];
			}else if(a[cc[i].num][1]<a[cc[i].num][3]&&a[cc[i].num][2]<a[cc[i].num][1]){
				aaa--,ccc++,ans=ans-a[cc[i].num][1]+a[cc[i].num][3];
			}else if(a[cc[i].num][1]==a[cc[i].num][2]&&a[cc[i].num][2]<a[cc[i].num][3]){
				aaa--,ccc++,ans=ans-a[cc[i].num][2]+a[cc[i].num][3];
			}
		}
		for(int i=1;i<=n;i++){
			ls=max(a[i][1],max(a[i][2],a[i][3]));
			if(ls==a[i][1]){
				xx[i].sum=10000000007,yy[i].sum=ls-a[i][2],zz[i].sum=ls-a[i][3];
			}else if(ls==a[i][2]){
				xx[i].sum=ls-a[i][1],yy[i].sum=10000000007,zz[i].sum=ls-a[i][3];
			}else{
				xx[i].sum=ls-a[i][1],yy[i].sum=ls-a[i][2],zz[i].sum=10000000007;
			}
			xx[i].num=i,yy[i].num=i,zz[i].num=i;
		}
		if(aaa>n/2){
			for(int i=1;i<=n;i++){
				if(xx[i].sum==10000000007) dd[i]=min(xx[i].sum,min(yy[i].sum,zz[i].sum));
				else dd[i]=10000000007;
			}
			sort(dd+1,dd+n+1,cmp2);
			for(int i=1;i<=aaa-n/2;i++){
				ans-=dd[i];
			}
		}else if(bbb>n/2){
			for(int i=1;i<=n;i++){
				if(yy[i].sum==10000000007) dd[i]=min(xx[i].sum,min(yy[i].sum,zz[i].sum));
				else dd[i]=10000000007;
			}
			sort(dd+1,dd+n+1,cmp2);
			for(int i=1;i<=bbb-n/2;i++){
				ans-=dd[i];
			}
		}else if(ccc>n/2){
			for(int i=1;i<=n;i++){
				if(zz[i].sum==10000000007) dd[i]=min(xx[i].sum,min(yy[i].sum,zz[i].sum));
				else dd[i]=10000000007;
			}
			sort(dd+1,dd+n+1,cmp2);
			for(int i=1;i<=ccc-n/2;i++){
				ans-=dd[i];
			}
		}
		cout<<ans<<endl;
		t--;
	}
	
	return 0;
} 
