#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int T,fl2,n,x,y,z,i,fl3,ans,ma,f[410][410][410];
struct no{
	int x,y,z;
}a[100010];
bool cmp(no q,no h){
	return q.x>h.x;
}
main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;ma=ans=0;fl2=fl3=1;
		for(i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0)fl2=0;
			if(a[i].z!=0)fl3=0;
		}
		if(fl2&&fl3){
			sort(a+1,a+1+n,cmp);
			for(i=1;i<=n/2;i++)ans+=a[i].x;
			cout<<ans<<"\n";
		}
		else{
			memset(f,0,sizeof(f));
			f[0][0][1]=a[1].z;
			f[0][1][0]=a[1].y;
			f[1][0][0]=a[1].x;
			for(i=1;i<n;i++)
				for(x=0;x<=min(n/2,i);x++)
					for(y=0;y<=min(n/2,i-x);y++)
						if(i-x-y<=n/2)
							z=i-x-y,
							f[x+1][y][z]=max(f[x+1][y][z],f[x][y][z]+a[i+1].x),
							f[x][y+1][z]=max(f[x][y+1][z],f[x][y][z]+a[i+1].y),
							f[x][y][z+1]=max(f[x][y][z+1],f[x][y][z]+a[i+1].z);
			for(x=0;x<=n/2;x++)
				for(y=0;y<=n/2;y++)
					if(n-x-y<=n/2)
					ma=max(ma,f[x][y][n-x-y]);
			cout<<ma<<"\n";
		}
	}
}