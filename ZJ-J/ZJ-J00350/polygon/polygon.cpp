#include<bits/stdc++.h>
using namespace std;
long long n,a[5100],ans,m[5010][5010];
int f(int x,int y){
//	cout<<x<<' '<<y<<endl;
	
	if(x==0&&y<0) return 1;
	if(y<0){
		m[x][y]=(f(x-1,y)*2)%998244353;
		return m[x][y];
	}
	if(x<=0) return 0;
	if(x==1){
		if(a[1]>y) m[x][y]=1;
		else m[x][y]=0;
		return m[x][y];
	}
	if(m[x][y]>=0){
		return m[x][y];
	}
	m[x][y]=(f(x-1,y)%998244353+f(x-1,y-a[x])%998244353)%998244353;
	return m[x][y];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(m,-127,sizeof(m));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans+=f(i-1,a[i]);
	//	if(a[i]==a[i+1]) ans+=f(i-1,a[i]);
	}
	cout<<ans%998244353;
	return 0;
}
//J-00350