#include<bits/stdc++.h>
#define ll long long
#define low(X) (X&(-X))
#define pb(A) push_back(A)
#define mk(A,B) make_pair(A,B)
using namespace std;
ll read(){
	ll S=0,F=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')F*=-1;
		ch=getchar();
	}while(isdigit(ch)){
		S=(S<<3)+(S<<1)+(ch^48);
		ch=getchar();
	}return S*F;
}const int N=1e5;
int T,n,a[N+10][4],cho[N+10],buc[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	vector<int>chan;
	T=read();while(T--){
		n=read();
		ll ans=0;buc[1]=buc[2]=buc[3]=0;
		for(int i=1;i<=n;i++){
			a[i][0]=-1;cho[i]=0;
			for(int j=1;j<=3;j++){
				a[i][j]=read();
				if(a[i][j]>a[i][cho[i]])cho[i]=j;
			}buc[cho[i]]++;
			ans+=a[i][cho[i]];
		}int lim=0;
		for(int i=1;i<=3;i++)if(buc[i]*2>n)lim=i;
		if(lim){
			chan.clear();
			for(int i=1;i<=n;i++){
				int maxn=0;
				for(int j=1;j<=3;j++)if(j!=lim)maxn=max(maxn,a[i][j]);
				if(cho[i]==lim)chan.pb(a[i][lim]-maxn);
			}sort(chan.begin(),chan.end());
			for(int i=0;i<buc[lim]-n/2;i++)ans-=chan[i];
		}printf("%lld\n",ans);
	}
	return 0;
}
