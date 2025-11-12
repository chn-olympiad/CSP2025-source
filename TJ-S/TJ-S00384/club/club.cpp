#include<iostream>
#include<algorithm>
using namespace std;
//Ren5Jie4Di4Ling5%
struct ee{
	int a,b,c;
};
ee a[100005];
int n,t;
int ans=-1,ansl[100005],opt[100005],mx[4],la,lb,lc,checkb=0,checkc=0;
bool cmp(ee x,ee y){
	return max(x.a-x.b-x.c,max(x.b-x.c-x.a,x.c-x.b-x.a))>=max(y.a-y.b-y.c,max(y.b-y.c-y.a,y.c-y.b-y.a));
}
bool cmpbc(ee x,ee y){
	return x.a>y.a;
}
int k(int i,int j){
	if(j==1){
		return (a[i].a-a[i].b-a[i].c);
	}
	if(j==2){
		return (a[i].b-a[i].a-a[i].c);
	}
	if(j==3){
		return (a[i].c-a[i].a-a[i].b);
	}
}
//mhyÉñÁ¦ 
//void dfs(int c,int na,int nb,int nc,int now){
//	if(c==n+1){
//		if(now>ans){
//			for(int i=1;i<=n;i++){
//				ansl[i]=opt[i];
//			}
//			ans=now;
//		}
//		return;
//	}
//	if(na<n/2){
//		opt[c]=1;
//		dfs(c+1,na+1,nb,nc,now+a[c].a);
//	}
//	if(nb<n/2){
//		opt[c]=2;
//		dfs(c+1,na,1+nb,nc,now+a[c].b);
//	}
//	if(nc<n/2){
//		opt[c]=3;
//		dfs(c+1,na,nb,nc+1,now+a[c].c);
//	}
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int h=1;h<=t;h++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0){
				checkb=1;
			}
			if(a[i].c!=0){
				checkc=1;
			}
		} 
		if(checkc==0){
			if(checkb==0){
				sort(a+1,a+n+1,cmpbc);
				int nna=0;
				ans=0;
				for(int i=1;i<=n;i++){
					if(nna<n/2&&a[i].a>0){
						ans+=a[i].a;
						nna++;
					}
				}
				cout<<ans;
				return 0;
			}
		}
		sort(a+1,a+1+n,cmp);
		ans=0;
		la=0;
		lb=0;
		lc=0;
		for(int i=1;i<=n;i++){
//			if(a[i].a>max(a[i].b,a[i].c)){
//				mx[1]=1;
//				if(a[i].b>a[i].c){
//					mx[2]=2;
//					mx[3]=3;
//				}else{
//					mx[3]=2;
//					mx[2]=3;
//				}
//			}else if(a[i].b>max(a[i].a,a[i].c)){
//				mx[1]=2;
//				if(a[i].a>a[i].c){
//					mx[2]=1;
//					mx[3]=3;
//				}else{
//					mx[2]=3;
//					mx[3]=1;
//				}
//			}else if(a[i].c>max(a[i].b,a[i].a)){
//				mx[1]=3;
//				if(a[i].a>a[i].b){
//					mx[2]=1;
//					mx[3]=2;
//				}else{
//					mx[3]=1;
//					mx[2]=2;
//				}
//			}
			int aa=k(i,1);
			int bb=k(i,2);
			int cc=k(i,3);
			if(aa>max(bb,cc)){
				mx[1]=1;
				if(bb>cc){
					mx[2]=2;
					mx[3]=3;
				}else{
					mx[2]=3;
					mx[3]=2;
				}
			}else if(bb>max(aa,cc)){
				mx[1]=2;
				if(aa>cc){
					mx[2]=1;
					mx[3]=3;
				}else{
					mx[2]=3;
					mx[3]=1;
				}
			}else if(cc>max(bb,aa)){
				mx[1]=3;
				if(bb>aa){
					mx[2]=2;
					mx[3]=1;
				}else{
					mx[2]=1;
					mx[3]=2;
				}
			}
//			cout<<endl<<"mx "<<mx[1]<<' '<<mx[2]<<' '<<mx[3];
			for(int j=1;j<=3;j++){
				if(mx[j]==1){
					if(la<n/2){
						la++;
						ans+=a[i].a;
						break;
					}
				}else if(mx[j]==2){
					if(lb<n/2){
						lb++;
						ans+=a[i].b;
						break;
					}
				}else if(mx[j]==3){
					if(lc<n/2){
						lc++;
						ans+=a[i].c;
						break;
					}
				}
			}
		}
//		cout<<"\n--------------------";
		cout<<ans<<endl;
	}
	
	return 0;
} 
