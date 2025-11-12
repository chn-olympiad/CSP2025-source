#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mk make_pair
#define fir first
#define sec second
#define put putchar
using namespace std;
int rd(){
	int sum=0,p=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')p=-1;ch=getchar();}
	while(isdigit(ch)){sum=sum*10+(ch-'0');ch=getchar();}
	return sum*p;
}
void wr(int x){
	if(x<0)put('-'),x=-x;
	if(x>9)wr(x/10);
	put(x%10+'0');
}
const int JYAAKIOI=1e18,N=1e5+10;
struct node{
	int x,y,z;
}a[N];
int T,n,ans,b[N],f[210][210][210];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=rd();
	while(T--){
		ans=0;
		n=rd();
		bool fl1=1,fl2=1;
		for(int i=1;i<=n;++i){
			a[i].x=rd();a[i].y=rd();a[i].z=rd();
			if(!(a[i].y==0&&a[i].z==0))fl1=0;
			if(!(a[i].z==0))fl2=0;
			//ans+=a[i].x;
			//b[i]=(info){a[i].y-a[i].x,a[i].z-a[i].x};
			//c[i]=b[i];
		}
//		cout<<ans<<"\n";
//		for(int i=1;i<=n;++i)cout<<a[i].x-a[i].y<<' '<<a[i].x-a[i].z<<endl;
		/*sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n;++i){
			//cout<<b[i].w1<<' '<<b[i].w2<<endl;
		}
		//pos1=0,pos2=n+1;
		pre[0]=suf[n+1]=0;
		for(int i=1;i<=n;++i)pre[i]=pre[i-1]+b[i].w1;
		for(int i=n;i>=1;--i)suf[i]=suf[i+1]+b[i].w2;
		for(int i=n;i>=1;--i)suf[i]=max(suf[i],suf[i+1]);
		int maxn=-JYAAKIOI;
		for(int i=0;i<=n/2;++i){
			if(pre[i]+suf[n/2+1]>maxn){
				maxn=pre[i]+suf[n/2+1];
			//	pos1=i,pos2=n-(n/2-i)+1;
			}
		}
		ans+=maxn;
		/*while(pos1<n/2||pos2>n/2+1){
			if(pos1==n/2){
				if(b[pos2-1].w2<=0)break;
				--pos2;
				ans+=b[pos2].w2;
			}
			else if(pos2==n/2+1){
				if(b[pos1+1].w1<=0)break;
				++pos1;
				ans+=b[pos1].w1;
			}
			else{
				if(b[pos2-1].w2<=0&&b[pos1+1].w1<=0)break;
				if(b[pos1+1].w1<=b[pos2-1].w2){
					--pos2;
					ans+=b[pos2].w2;
				}
				else{
					++pos1;
					ans+=b[pos1].w1;
				}
			}
		}*/
		if(n<=200){
			for(int i=0;i<=n;++i){
				for(int j=0;j<=n;++j){
					for(int k=0;k<=n;++k){
						f[i][j][k]=0;
					}
				}
			}
			for(int i=1;i<=n;++i){
				for(int j=0;j<=min(i,n);++j){
					for(int k=0;k<=min(i-j,n);++k){
						if(j)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i].x);
						if(k)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].y);
						if(i-j-k)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].z);
					}
				}
			}
			for(int i=0;i<=n/2;++i){
				for(int j=0;j<=n/2;++j){
					if(n-i-j<=n/2){
						ans=max(ans,f[n][i][j]);
					}
				}
			}
		}
		else{
			if(fl1||fl2){
				for(int i=1;i<=n;++i){
					ans+=a[i].x;
					b[i]=a[i].y-a[i].x;
				}
				sort(b+1,b+1+n);
				for(int i=n;i>=n/2+1;--i)ans+=b[i];
			}
			else{
				random_shuffle(a+1,a+1+n);
				for(int i=1;i<=n;++i){
					if(i<=n/3)ans+=a[i].x;
					else if(i<=n/3*2)ans+=a[i].y;
					else ans+=a[i].z;
				}
				wr(ans),put('\n');
			}
		}
		wr(ans);put('\n');
	}
	return 0;
}
