#include<bits/stdc++.h>
using namespace std;
int n,a[500010],k,s[5000010][2],p,r,ans;
int yh(int x,int y){
	int s=0,l=0;
	bool f1[30]={0},f2[30]={0};
	while(x!=0||y!=0){
		l++;
		f1[l]=x%2,f2[l]=y%2;
		x/=2,y/=2;
	}
	for(int i=l;i>=1;i--)s*=2,s+=f1[i]!=f2[i];
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=yh(a[i],a[i-1]);
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)if(yh(a[i-1],a[j])==k)s[++p][0]=i,s[p][1]=j;
	for(int i=1;i<=p;i++)if(s[i][0]>r)ans++,r=s[i][1];
	cout<<ans;
}
