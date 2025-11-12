#include<bits/stdc++.h>
using namespace std;
int n,d[3]={0,0,0},m[3]={1e9,1e9,1e9},ans=0;
struct node{//i是呈度排序,k是部门排序,ad是增量; 
	int a[3],i1=0,i2=0,i3=1e9,k1=0,k2=0,k3=0,ad[3],adm=0,adi;
}a[100001];
bool cmp1(node a,node b){
	return a.k1>b.k1;
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
	cin>>n;
	ans=0;
	d[0]=d[1]=d[2]=0;
	m[0]=m[1]=m[2]=1e9;
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<3;j++){
			cin>>a[i].a[j];
			a[i].i1=max(a[i].i1,a[i].a[j]);
			a[i].i3=min(a[i].i3,a[i].a[j]);
			sum+=a[i].a[j];
		}a[i].i2=sum-a[i].i1-a[i].i3;
	}for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			if(a[i].i1==a[i].a[j])a[i].k1=j;
			if(a[i].i2==a[i].a[j])a[i].k2=j;
			if(a[i].i3==a[i].a[j])a[i].k3=j;
		}
	}for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			m[j]=min(m[j],a[i].a[j]);
		}
	}for(int i=0;i<n;i++){
		a[i].adm=0;
		for(int j=0;j<3;j++){
			a[i].ad[j]=a[i].a[j]-m[j];
			a[i].adm=max(a[i].adm,a[i].ad[j]);
		}
	}for(int i=0;i<n;i++){
		d[a[i].k1]++;	
	}for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			if(a[i].ad[j]==a[i].adm)a[i].adi=j;
		}
	}
	for(int i=0;i<3;i++){
		if(d[i]>n/2){
			sort(a,a+n,cmp1);
			
			if(a[n/2].adm<a[n/2-1].adm&&a[n/2-1].adi!=i){
				a[n/2-1].k1=a[n/2-1].adi; 
			}else if(a[n/2].adm>=a[n/2-1].adm&&a[n/2-1].adi!=i){
				a[n/2].k1=a[n/2-1].adi; 
			}
		}
	}for(int i=0;i<n;i++){
		ans+=a[i].a[a[i].k1];
	}cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
