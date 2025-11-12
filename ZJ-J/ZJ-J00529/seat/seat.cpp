#include<bits/stdc++.h>
using namespace std;
int a[104];
int n,m;
int erfen(int i,int j,int cc){
	int mod=(i+j)/2,ans;
	while(i<=j){
		mod=(i+j)/2;
		if(a[mod]>cc){
			i=mod+1;
			ans=mod;
		}
		else{
			j=mod-1;
			ans=mod;
		}
	}
	return ans;
}
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int b=erfen(1,n*m,x);
	cout<<ceil(1.0*b/m)<<' ';
	if((int)ceil(1.0*b/m)%2==1)cout<<b-(ceil(1.0*b/m)-1)*n;
	else cout<<n-(b-(ceil(1.0*b/m)-1)*n)+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

