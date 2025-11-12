#include<bits/stdc++.h>
using namespace std;
struct p{
	int a,b,c;
	int cha;
};
inline void huan(int &a,int &b){
	int aa=a,bb=b;
	b=aa,a=bb;
	return;
}
inline int se(int a,int b,int c){
	if(a<b) huan(a,b);
	if(a<c) huan(a,c);
//	cout<<a<<" "<<b<<' '<<c<<endl;
	if(b<c) huan(b,c);
	return b;
}
inline bool cmp(p &x,p &y){
	return x.cha<y.cha;
}
p per[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n,cnta=0,cntb=0,cntc=0;cin>>n;
		for(int i=1;i<=n;++i){
			int a,b,c;cin>>a>>b>>c;per[i].a=a;per[i].b=b;per[i].c=c;
			if(a>=b&&a>=c) cnta++;
			else if(b>=c&&b>=a) cntb++;
			else cntc++;
		//	else cout<<"ER";
		}
	//	cout<<cnta<<" "<<cntb<<" "<<cntc<<endl;
		int ans=0;
		for(int i=1;i<=n;++i) ans+=max(per[i].a,max(per[i].b,per[i].c));
		int mx=max(cnta,max(cntb,cntc));
	//	cout<<"mx::"<<max(cnta,max(cntc,cntb))<<endl;
		if(n/2>=mx){
			cout<<ans<<endl;
			//cout<<"meow"<<endl;
		}else{
			for(int i=1;i<=n;++i){
				int a=per[i].a,b=per[i].b,c=per[i].c;
				per[i].cha=max(a,max(b,c))-se(a,b,c);
			}
			sort(per+1,per+1+n,cmp);
			int num=max(cnta,max(cntb,cntc))-n/2;
			int flag;
			if(cnta>n/2) flag=1;
			if(cntb>n/2) flag=2;
			if(cntc>n/2) flag=3;
			for(int i=1,j=1;i<=num;j++){
				int a=per[j].a,b=per[j].b,c=per[j].c;
				if(flag==1&&max(a,max(b,c))!=a) continue; 
				if(flag==2&&max(a,max(b,c))!=b) continue; 
				if(flag==3&&max(a,max(b,c))!=c) continue; 
				ans-=per[j].cha;
				i++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
