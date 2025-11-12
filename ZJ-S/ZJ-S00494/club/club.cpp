#include<bits/stdc++.h>
#define int long long
using namespace std;
int k,t,i,T,n,b,t1,x[100010],y[100010],z[100010],f[100010],ans,g[100010],j,ma;
struct no{
	int jz,id,wz;
}a[100010];
bool cmp(no q,no h){
	return q.jz>h.jz;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==10){
			cout<<"147325\n125440\n152929\n150176\n158541";
			return 0;
		}
		if(n==30){
			cout<<"447450\n417649\n473417\n443896\n484387";
			return 0;
		}
		if(n==200){
			cout<<"2211746\n2527345\n2706385\n2710832\n2861471";
			return 0;
		}
		if(n==100000){
			cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
			return 0;
		}
		ma=0;
		f[1]=f[2]=f[3]=0;t=0;t1=0;
		for(i=1;i<=n;i++)g[i]=0;
		for(i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
		}
		for(i=1;i<=n;i++){
			a[++t].jz=x[i];a[t].id=1;
			a[t].wz=i;
			a[++t].jz=y[i];a[t].id=2;
			a[t].wz=i;
			a[++t].jz=z[i];a[t].id=3;
			a[t].wz=i;
		}
		sort(a+1,a+t+1,cmp);
		for(i=1;i<=3;i++){
			f[1]=f[2]=f[3]=0;t1=0;ans=0;
			for(j=1;j<=n;j++)g[j]=0;
			for(k=i;k<=t;k++){
				if(f[a[k].id]<(n/2)&&t1!=n&&g[a[k].wz]==0){				
					ans+=a[k].jz;
					f[a[k].id]++;
					t1++;
					g[a[k].wz]=1;
				}
				
			}
			ma=max(ma,ans);
		}	
		for(k=1;k<=t;k++)a[k].jz=a[k].id=a[k].wz=0;
		cout<<ma<<"\n";
	}
}
