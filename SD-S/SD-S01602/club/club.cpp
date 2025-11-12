#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
//read
int n;
int vis[N];
struct node{
	int a1,a2,a3;
	int id;
}a[N];
int anss=0;
int f[202][202][202];
int mi(int x,int y){
	if(x<y) return x;
	else return y;
}
bool cmp(node x,node y){
	return x.a1-x.a2>y.a1-y.a2;
}
bool cmp1(node x,node y){
	return mi(x.a1-x.a3,x.a1-x.a2)>mi(y.a1-y.a3,y.a1-y.a2);
}
bool cmp2(node x,node y){
	return x.a2-x.a3>y.a2-y.a3;
}
void hhhsolve(){
	int ans=0;
	sort(a+1,a+1+n,cmp1);
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(mi(a[i].a1-a[i].a2,a[i].a1-a[i].a3)>=0){
			cnt++;
			ans+=a[i].a1;
			vis[a[i].id]=1;
		//	cout<<"1:"<<a[i].id<<endl;
			if(cnt>=n/2) break;
		}
	}
	sort(a+1,a+1+n,cmp2);
	cnt=0;int c3=0;
	int mst=0;
	for(int i=1;i<=n;++i){
		if(vis[a[i].id]) continue;
		if(cnt<n/2||c3==n/2){
			if(a[i].a2>=a[i].a3||c3==n/2){
				cnt++;
				ans+=a[i].a2;	
			}else{
				c3++;
				ans+=a[i].a3;
				if(c3==n/2) mst=1;
			}
		//	cout<<"2:"<<a[i].id<<endl;
			vis[a[i].id]=1;
		}else{
		//	cout<<"3:"<<a[i].id<<endl;
			ans+=a[i].a3;
			c3++;
			if(c3==n/2) mst=1;
		}
	}
	anss=max(anss,ans);
//	printf("%d\n",ans);
}
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		n=read();
		int fl1=0,fl2=0;
		for(int i=1;i<=n;i++){
			a[i].a1=read();
			a[i].a2=read();
			a[i].a3=read();
			a[i].id=i;
			vis[i]=0;
			if(a[i].a3!=0) fl1=1;
			if(a[i].a2!=0) fl2=1;
		}
		int ans=0;
	/*	if(fl1==0){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(i<=n/2) ans+=a[i].a1;
				else ans+=a[i].a2;
			}
			printf("miao %d\n",ans);
			continue;
		}*/
		if(n>200){
			anss=0;
			hhhsolve();
				for(int i=1;i<=n;++i){
				int o=a[i].a1;
				a[i].a1=a[i].a3;
				a[i].a3=o;
				vis[i]=0;
			}
			hhhsolve();
		for(int i=1;i<=n;++i){
				int o=a[i].a2;
				a[i].a2=a[i].a3;
				a[i].a3=o;
				vis[i]=0;
			}
			hhhsolve();
			for(int i=1;i<=n;++i){
				int o=a[i].a1;
				a[i].a1=a[i].a3;
				a[i].a3=o;
				vis[i]=0;
			}
			hhhsolve();
			printf("%d\n",anss);
			continue;
		}
	//	memset(f,0,sizeof f);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i,n/2);k++){
					f[i][j][k]=0;
				//	cout<<i<<" "<<j<<" "<<k<<endl;
					if(j!=0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i].a1);
					if(k!=0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].a2);
					if(i-j-k<=n/2&&i-j-k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].a3);
					if(i==n) ans=max(ans,f[i][j][k]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
