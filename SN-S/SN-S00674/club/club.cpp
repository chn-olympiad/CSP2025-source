#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int T,n;
struct qq{
	int i1,i2,i3;
}a[N];

bool cmp(qq x,qq y){
	return x.i1>y.i1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==2){
			int z,x,c,v,b,n,m[10]={0,0,0,0,0,0,0,0,0,0};
			cin>>z>>x>>c>>v>>b>>n;
			m[0]=z+b;
			m[1]=z+n;
			m[2]=x+v;
			m[3]=x+n;
			m[4]=c+v;
			m[5]=c+b;
			sort(m,m+6);
			cout<<m[5]<<endl;
			
		}else{
			int aa=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].i1,&a[i].i2,&a[i].i3);
			if(a[i].i2==0&&a[i].i3==0){
				++aa;
			}
		}
		if(aa==n){
			sort(a+1,a+1+n,cmp);
			long long ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].i1;
			}
			cout<<ans<<endl;
		}
		for(int i=1;i<=n;i++){
			a[i].i1=0,a[i].i2=0,a[i].i3=0;
		}}
		
	}
	return 0;
}
