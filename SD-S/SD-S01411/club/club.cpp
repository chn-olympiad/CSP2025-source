#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;i++)
#define R(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const ll N=2e5+7;
ll t,n,a[N][4],tot[4],mx[N],mx2[N],id[N],id2[N];
struct edge{
	int cha,id;
	bool operator<(const edge& x)const{
		return cha<x.cha;
	}
}b[N];
inline ll fr(){
	ll s=0,k=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') k=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*k;
}
inline void fw(ll x){
	if(x>9) fw(x/10);
	putchar((x%10)+'0');
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	t=fr();
	while(t--){
		n=fr();
		F(i,1,n){
			mx[i]=id[i]=mx2[i]=id2[i]=0;
		}
		ll mxv=0,mxid=0,mxcnt=n/2,ans=0;
		tot[1]=tot[2]=tot[3]=0;
		F(i,1,n){
			F(j,1,3){
				a[i][j]=fr();
			}
			F(j,1,3){
				if(a[i][j]>mx[i]){
					id[i]=j;
					mx[i]=a[i][j];
				}
			}
			ans+=mx[i];
			F(j,1,3){
				if(a[i][j]>mx2[i]&&j!=id[i]){
					mx2[i]=a[i][j];
					id2[i]=j;
				}
			}
			tot[id[i]]++;
		}
		F(i,1,3){
			if(tot[i]>mxv){
				mxv=tot[i];
				mxid=i;
			}
		}
		if(mxv>n/2){
			int cnt=0;
			F(i,1,n){
				if(id[i]==mxid){
					b[++cnt].cha=mx[i]-mx2[i];
				}
			}
			sort(b+1,b+cnt+1);
//			cout<<"ans:"<<ans<<"\n";
//			cout<<mxv<<"\n";
//			F(i,1,n){
//				cout<<b[i].cha<<" ";
//			}
//			cout<<"\n";
			F(i,1,mxv-n/2){
				ans-=b[i].cha;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
