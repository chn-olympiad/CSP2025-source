#include<bits/stdc++.h>
//#include<windows.h>
#define int long long
#define p 998244353
#define c 114514
using namespace std;
inline int qp(int x,int y){
	if(y==1) return x;
	if(y==0) return 1;
	int ans=qp(x,y/2);
	ans*=ans,ans%=p;
	if(y%2==1) ans*=x,ans%=p;
	return ans;
}
int tp;
int ll[200009],rr[200009];
int mi[5000009],ni[5000009],ha[5000009],lll[200009],llll[200009],lllll[200009],llllll[200009],ha2[5000009];
inline int qu(int l,int r){
	if(l>r) return 0;
	return (ha[r]-ha[l-1]+p)*ni[l-1]%p;
}
inline int qu2(int l,int r){
	if(l>r) return 0;
	return (ha2[r]-ha2[l-1]+p)*ni[l-1]%p;
}
struct n4{
	map<int,map<int,int> > cc;
	inline void add(int x,int y){
		while(x<=5e6){int yy=y;
			while(yy<=5e6) cc[x][yy]++,yy+=(yy&-yy);x+=(x&-x);
		}
	}
	inline int que(int x,int y){int ans=0;
		while(x){
			int yy=y;
			while(yy) ans+=cc[x][yy],yy-=(yy&-yy);x-=(x&-x);
		}return ans;
	}
}cc[10000009];
signed main(){//cout<<sizeof cc;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	mi[0]=1;
	for(int i=1;i<=5000000;i++) mi[i]=mi[i-1]*c%p;
	ni[5000000]=qp(mi[5000000],p-2);
	for(int i=4999999;i>=0;i--) ni[i]=ni[i+1]*c%p;
	int nn,q;cin>>nn>>q;
	if(nn*q<=10000000){
		string sl,sr;
		for(int i=1;i<=nn;i++){tp=0;
			cin>>sl>>sr;
			tp=sl.size();
			sl=' '+sl,sr=' '+sr;
			int l=-1,r=-1;
			for(int j=1;j<=tp;j++){
				if(sl[j]!=sr[j]){
					l=j;break;
				}
			}
			for(int j=tp;j>=1;j--){
				if(sl[j]!=sr[j]){
					r=j;break;
				}
			}
			ll[i]=l,rr[i]=r;
			if(l==-1) continue;
			for(int j=1;j<=tp;j++){
				ha[j]=(ha[j-1]+sl[j]*mi[j-1])%p;
			}
			lll[i]=qu(1,l-1),llll[i]=qu(l,r),lllll[i]=qu(r+1,tp);
			for(int j=1;j<=tp;j++){
				ha[j]=(ha[j-1]+sr[j]*mi[j-1])%p;
			}llllll[i]=qu(l,r);
			
		}string s,ss;
		while(q--){
			cin>>s>>ss;
			int n=s.size(),m=s.size();
			if(n!=m){
				printf("0\n");continue;
			}
			s=' '+s,ss=' '+ss;
			int l=-1,r=-1;
			for(int i=1;i<=n;i++){
				if(s[i]!=ss[i]) {
					l=i;break;
				}
			}
			for(int i=n;i>=1;i--){
				if(s[i]!=ss[i]){
					r=i;break;
				}
			}
			for(int i=1;i<=n;i++) ha[i]=(ha[i-1]+s[i]*mi[i-1])%p;
			map<int,int> mpl,mpr;
			for(int i=1;i<=n;i++) ha2[i]=(ha2[i-1]+ss[i]*mi[i-1])%p;
			mpl[0]=1,mpr[0]=1;
			for(int i=1;i<=l-1;i++) mpl[qu(i,l-1)]++;
			for(int i=r+1;i<=n;i++) mpr[qu(r+1,i)]++;int sum=0;
			for(int i=1;i<=nn;i++){
				if(mpl.count(lll[i])&&mpr.count(lllll[i])&&qu(l,r)==llll[i]&&qu2(l,r)==llllll[i]) sum++;
			}
			printf("%lld\n",sum);
			//Sleep(100);
	//		int ll=qu(1,l-1),lll=qu(l,r),llll=qu(r+1,n);
	//		
	//		int lllll=qu(l,r);
	//		if(mp.count({ll,{lll,{llll,lllll}}})) {
	//			int kkk=mp[{ll,{lll,{llll,lllll}}}];
	//			printf("%lld\n",kkk);
	//		}
	//		else printf("0\n");
		}return 0;
	}
	for(int i=1;i<=nn;i++){
		string x,y;cin>>x>>y;int fll=1;
		int n=x.size();x=' '+x;
		for(int i=1;i<=n;i++) if(x[i]>'b'||y[i]>'b') fll=0;
		if(fll==0) break;
		for(int i=1;i<=n;i++) if(x[i]=='b') fll--;
		if(fll!=0) break;fll=1;
		for(int i=1;i<=n;i++) if(y[i]=='b') fll--;
		if(fll!=0) break;
		int xl,xr;
		for(int i=1;i<=n;i++){
			if(x[i]=='b') xl=i;
			if(y[i]=='b') xr=i;
		}
		cc[xr-xl+5000000].add(xl,n-xr+1);
		//c[]
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		int n=x.size(),m=y.size();x=' '+x,y=' '+y;
		if(n!=m){
			printf("0\n");continue;
		}
		int xl,xr;
		for(int i=1;i<=n;i++){
			if(x[i]=='b') xl=i;
			if(y[i]=='b') xr=i;
		}
		cout<<cc[xr-xl+5000000].que(xl,n-xr+1)<<'\n';
	}
	return 0;
}
