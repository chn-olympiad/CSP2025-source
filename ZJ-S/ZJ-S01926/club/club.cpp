#include<bits/stdc++.h>
using namespace std;
int T,n,a[100002],b[100002],c[100002],s1[100002],s2[100002],s3[100002],k1,k2,k3,ans,x;
bool cmp(int x,int y){
	if(a[x]<b[x])swap(a[x],b[x]);
	if(a[x]<c[x])swap(a[x],c[x]);
	if(b[x]<c[x])swap(c[x],b[x]);
	if(a[y]<b[y])swap(a[y],b[y]);
	if(a[y]<c[y])swap(a[y],c[y]);
	if(b[y]<c[y])swap(c[y],b[y]);
	return a[x]-b[x]<a[y]-b[y];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		k1=k2=k3=ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]){
				if(a[i]>=c[i])s1[++k1]=i;
				else s3[++k3]=i;
			}
			else{
				if(b[i]>=c[i])s2[++k2]=i;
				else s3[++k3]=i;
			}
			ans+=max(a[i],max(b[i],c[i]));
		}
		if(k1>n/2){
			sort(s1+1,s1+k1+1,cmp);
			for(int i=1;i<=k1-n/2;i++)ans-=a[s1[i]]-b[s1[i]];
		}
		else if(k2>n/2){
			sort(s2+1,s2+k2+1,cmp);
			for(int i=1;i<=k2-n/2;i++)ans-=a[s2[i]]-b[s2[i]];
		}
		else if(k3>n/2){
			sort(s3+1,s3+k3+1,cmp);
			for(int i=1;i<=k3-n/2;i++)ans-=a[s3[i]]-b[s3[i]];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
