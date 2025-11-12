#include<bits/stdc++.h>
using namespace std;
long long int n,k,vis[500050],er[500050],x,aa,tot,s,ss,ans;
int maxx;
struct node{
	long long int ej;
	int sj,sw;
}a[500050],sum[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].sj;
		aa=a[i].sj,x=0;
		memset(er,0,sizeof(er));
		while(aa){
			er[++x]=aa%2;
			aa/=2;
		}
		a[i].sw=x;
		for(int j=x;j>=1;j--) a[i].ej=a[i].ej*10+er[j];
		sum[1].ej=a[1].ej,maxx=sum[i].sw=max(maxx,a[i].sw);
		if(i!=1){
			sum[i].ej=sum[i-1].ej+a[i].ej;
			for(int j=1;j<=maxx;j++){
				tot=pow(10,j)/10;
				if(sum[i].ej/tot%10>=2) sum[i].ej-=(sum[i].ej/tot%10)*tot;
			} 
		}
	} 
	maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int flag=0;
			for(int q=i;q<=j;q++){
				if(vis[q]==1) flag=1;
			}
			if(flag==1) continue;
			ss=abs(sum[j].ej-sum[i-1].ej);
			maxx=max(sum[j].sw,sum[i].sw);
			s=0;
			for(int q=maxx;q>=1;q--){
				tot=pow(10,q)/10;
				s+=ss/tot;
				s*=2;
				ss=ss%tot;
			} 
			s/=2;
			if(i==j) s=a[i].sj;
			if(s==k){
				ans++;
				for(int q=i;q<=j;q++){
					vis[q]=1;
				}
			} 
			
		}
	}
	cout<<ans;
	//for(int i=1;i<=n;i++) cout<<a[i].sj<<" "<<a[i].ej<<" "<<sum[i].ej<<" "<<sum[i].sw<<"\n"; 
	return 0;
} 
