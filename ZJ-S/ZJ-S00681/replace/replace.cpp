#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+10;
int n,Q;
struct no{int jl,ljx,cyf,q,w;}k[100010];
char l[N][N],r[N][N],a[N],b[N];
int qa(){int x=1;while(a[x]>='a'&&a[x]<='z')x++;return x-1;}
int qb(){int x=1;while(b[x]>='a'&&b[x]<='z')x++;return x-1;}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	if(n>1000||Q>1000||Q==1){
		for(int i=1;i<=n;i++){
			cin>>a+1>>b+1;
			int la=qa(),lb=qb(),x=0,y=0;
			for(int i=1;i<=la;i++)
				if(a[i]=='b'){x=i;break;}
			for(int i=1;i<=lb;i++)
				if(b[i]=='b'){y=i;break;}
			k[i]=(no){x-y,x-1,la-x,y-1,lb-y};
		}
		cin>>a+1>>b+1;
		int la=qa(),lb=qb(),x=0,y=0;
		if(la!=lb){cout<<0;return 0;}
		for(int i=1;i<=la;i++)
			if(a[i]=='b'){x=i;break;}
		for(int i=1;i<=lb;i++)
			if(b[i]=='b'){y=i;break;}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(k[i].jl==x-y&&k[i].ljx<=x-1&&k[i].cyf<=la-x&&
			k[i].q<=y-1&&k[i].w<=la-y)ans++;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>l[i]+1>>r[i]+1;
	while(Q--){
		cin>>a+1>>b+1;
		int la=qa(),lb=qb();
		if(la!=lb){cout<<0<<"\n";continue;}
		int x,y;
		for(int i=1;i<=la;i++)
			if(a[i]!=b[i]){x=i;break;}
		for(int j=la;j>=1;j--)
			if(a[j]!=b[j]){y=j;break;}
		int ljx=y-x+1,ans=0;
		for(int i=1;i<=n;i++){
			int le=strlen(l[i]+1);
			for(int j=1;j<=le-ljx+1;j++){
				int flag=1;
				for(int k=j;k<=j+ljx-1;k++)
					if(l[i][k]!=a[x+k-j]){
						flag=0;break;
					}
				if(flag==1){
					int t=x-j+1,w=t+le-1;
					if(w<=la){
						int flag=1;
						for(int k=1;k<=le;k++)
							if(l[i][k]!=a[t+k-1]||r[i][k]!=b[t+k-1]){
								flag=0;break;
							}
						ans+=flag;
					}
				}
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=la;i++)a[i]=b[i]='A';		
	}
}