#include<bits/stdc++.h>
using namespace std;
#define v1 a[i].v[1]
#define v2 a[i].v[2]
#define v3 a[i].v[3]
int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=1e5+10;
int n;
struct node{
	int v[4],max1,max2,max3,mi;
}a[N];
void init(){
	for(int i=1;i<=n;i++){
		if(v1>=v2&&v2>=v3)a[i].max1=1,a[i].max2=2,a[i].max3=3;
		else if(v1>=v3&&v3>=v2)a[i].max1=1,a[i].max2=3,a[i].max3=2;
		else if(v2>=v1&&v1>=v3)a[i].max1=2,a[i].max2=1,a[i].max3=3;
		else if(v2>=v3&&v3>=v1)a[i].max1=2,a[i].max2=3,a[i].max3=1;
		else if(v3>=v1&&v1>=v2)a[i].max1=3,a[i].max2=1,a[i].max3=2;
		else if(v3>=v2&&v2>=v1)a[i].max1=3,a[i].max2=2,a[i].max3=1;
		a[i].mi=a[i].v[a[i].max2];
		v1-=a[i].mi;
		v2-=a[i].mi;
		v3-=a[i].mi;
	}
}
bool cmp(node x,node y){
	int t1=x.v[x.max1];
	int t2=y.v[y.max1];
	return t1>t2;
}
int main(){
	freopen("club.in","r",stdin);	
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		n=read();
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)a[i].v[j]=read();
		}
		init();
		sort(a+1,a+1+n,cmp);
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++)cout<<a[i].v[j]<<' ';
//				cout<<endl;
//		}
		int ans=0,c[4]={0};
		for(int i=1;i<=n;i++){
			int t1=a[i].max1,t2=a[i].max2,t3=a[i].max3;
			if(c[t1]<n/2){
				ans+=a[i].v[t1];
				c[t1]++;
			}
			else if(c[t2]<n/2){
				ans+=a[i].v[t2];
				c[t2]++;
			}
			else {
				ans+=a[i].v[t3];
				c[t3]++;
			}
			ans+=a[i].mi;
		}
		printf("%d\n",ans);
	}
	return 0;
}