#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,num=0;
long long ans=0,x=0,y=0,z=0,maxx;
struct node{
	long long a,b,c;
}a[N];
bool cmp1(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.b>y.b;
}
bool cmp3(node x,node y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		}
		maxx=0;
		int m=0;
		if(n%2==0){
			m=n/2;
		}else{
			m=n/2+1;
		}
		sort(a+1,a+n+1,cmp1);
		ans=0;
		num=0;
		for(int i=1;i<=n;i++){
			if(num<m){
				num+=1;
				ans+=a[i].a;
			}else{
				ans+=max(a[i].b,a[i].c);
			}
		}
		maxx=max(maxx,ans);
		sort(a+1,a+n+1,cmp2);
		ans=0;
		num=0;
		for(int i=1;i<=n;i++){
			if(num<m){
				num+=1;
				ans+=a[i].b;
			}else{
				ans+=max(a[i].a,a[i].c);
			}
		}
		maxx=max(maxx,ans);
		sort(a+1,a+n+1,cmp3);
		ans=0;
		num=0;
		for(int i=1;i<=n;i++){
			if(num<m){
				num+=1;
				ans+=a[i].c;
			}else{
				ans+=max(a[i].a,a[i].b);
			}
		}
		maxx=max(maxx,ans);
		cout<<maxx<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

