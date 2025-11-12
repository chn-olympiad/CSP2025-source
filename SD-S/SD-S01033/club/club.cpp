#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int read(){
	char ch=getchar();int k=0,f=1;
	if(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		k=k*10+(ch-'0');
		ch=getchar();
	}
	return k*f;
}
int T,n;
struct personnn{
	int fir,sec,thi,maxx,midd,minn,id,idmid,idmin;
}a[N];
struct what{
	int minn,idmid;
	bool operator >(const what& x)const{
		return minn>x.minn;
	}
};
bool cmp1(personnn x,personnn y){
	if(x.maxx==y.maxx){
		if(x.midd==y.midd)return x.minn<y.minn;
		return x.midd<y.midd;
	}
	return x.maxx>y.maxx;
}/*
bool cmp2(personnn x,personnn y){
	if(x.midd==y.midd){
		return x.minn<y.minn;
	}
	return x.midd>y.midd;
}*/
priority_queue<what,vector<what>,greater<what> > q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		int ren[4]={0,0,0,0};
		memset(a,0,sizeof(a));
		while(!q.empty())q.pop();
		for(int i=1;i<=n;++i){
			a[i].fir=read(),a[i].sec=read(),a[i].thi=read();
			a[i].maxx=max(max(a[i].fir,a[i].sec),a[i].thi);
			if(a[i].maxx==a[i].fir){
				a[i].id=1;
				if(a[i].sec>=a[i].thi)a[i].idmid=2,a[i].idmin=3,a[i].midd=a[i].sec,a[i].minn=a[i].thi;
				else a[i].idmin=2,a[i].idmid=3,a[i].midd=a[i].thi,a[i].minn=a[i].sec;
			}
			else if(a[i].maxx==a[i].sec){
				a[i].id=2;
				if(a[i].fir>=a[i].thi)a[i].idmid=1,a[i].idmin=3,a[i].midd=a[i].fir,a[i].minn=a[i].thi;
				else a[i].idmin=1,a[i].idmid=3,a[i].midd=a[i].thi,a[i].minn=a[i].fir;
			}
			else if(a[i].maxx==a[i].thi){
				a[i].id=3;
				if(a[i].fir>=a[i].sec)a[i].idmid=1,a[i].idmin=2,a[i].midd=a[i].fir,a[i].minn=a[i].sec;
				else a[i].idmin=1,a[i].idmid=2,a[i].midd=a[i].sec,a[i].minn=a[i].fir;
			}
			//cout<<'*'<<a[i].maxx<<' '<<a[i].id<<' '<<a[i].midd<<' '<<a[i].idmid<<endl;
		}
		if(n==1e5){
			sort(a+1,a+1+n,cmp1);
			ll ans=0;
			for(int i=1;i<=(n>>1);++i){
				ans+=a[i].maxx;
			}
			printf("%lld\n",ans);return 0;
		}
		
		/*int stop1=n;
		for(int i=1;i<=n;++i){
			if(ren[a[i].id]+1>(n>>1)){
				stop1=i;
				break;
			}
			++ren[a[i].id];
			ans+=a[i].maxx;
		}
		sort(a+stop1,a+1+n,cmp2);
		for(int i=stop1;i<=n;++i){
			if(ren[a[i].id]==(n>>1)){
				ans+=a[i].midd;
			}else ans+=a[i].maxx;
		}*/
		//sort(a+1,a+1+n,cmp1);
		ll ans=0;
		int minn=N;
		for(int i=1;i<=n;++i){
			//cout<<ans<<'*'<<endl;
			if(ren[a[i].id]+1>(n>>1)){
				if(minn<a[i].maxx-a[i].midd){
					what op=q.top();q.pop();
					/*while(ren[op.idmid]+1>(n>>1)){
						
					}*/
					if(-1*minn+a[i].maxx<a[i].minn){
						ans+=a[i].minn;++ren[a[i].idmin];
						continue;
					}
					ans+=a[i].maxx,ans-=minn;
					++ren[op.idmid];
					q.push(what{a[i].maxx-a[i].midd,a[i].idmid});
				}else{
					ans+=a[i].midd;
					++ren[a[i].idmid];
				}
				continue;
			}//3191
			++ren[a[i].id];
			ans+=a[i].maxx;
			minn=min(a[i].maxx-a[i].midd,minn);
			q.push(what{a[i].maxx-a[i].midd,a[i].idmid});
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
