#include<bits/stdc++.h>
#define int long long
#define N 1000010
using namespace std;
int T,n,i,c[N],t,b[N],f[5],ans;
struct no{
	int x,y,z;
}a[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;ans=0;memset(f,0,sizeof(f));t=0;
		for(i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
				f[1]++,ans+=a[i].x,b[i]=1;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
				f[2]++,ans+=a[i].y,b[i]=2;
			else if(a[i].z>=a[i].x&&a[i].z>=a[i].y)
				f[3]++,ans+=a[i].z,b[i]=3;
		}
		if(f[1]>n/2||f[2]>n/2||f[3]>n/2){
			if(f[1]>n/2){
				for(i=1;i<=n;i++)
					if(b[i]==1)t++,c[t]=min
					(a[i].x-a[i].y,a[i].x-a[i].z);
				sort(c+1,c+1+t);
				for(i=1;i<=t-n/2;i++)
					ans-=c[i];
				cout<<ans<<"\n";
			}
			if(f[2]>n/2){
				for(i=1;i<=n;i++)
					if(b[i]==2)t++,c[t]=min
					(a[i].y-a[i].x,a[i].y-a[i].z);
				sort(c+1,c+1+t);
				for(i=1;i<=t-n/2;i++)
					ans-=c[i];
				cout<<ans<<"\n";
			}
			if(f[3]>n/2){
				for(i=1;i<=n;i++)
					if(b[i]==3)t++,c[t]=min
					(a[i].z-a[i].y,a[i].z-a[i].x);
				sort(c+1,c+1+t);
				for(i=1;i<=t-n/2;i++)
					ans-=c[i];
				cout<<ans<<"\n";
			}
		}
		else cout<<ans<<"\n";
	}
	return 0;
}
/*
		if(xa==xb&&ya==yb){
			system("cls");
			cout<<"Game Over!\n";Sleep(1000);
			cout<<"You are win!";return 0;
		}
*/