#include<bits/stdc++.h>
using namespace std;
struct p{
	int key,like;
};
int t;
map<int,int>m[100010];
int a[100010][4],c[3][100010],z[4],c1[100010][3],b[100010][4];
bool cmp(int x,int y){
	return x<y;
}
bool cmp2(p x,p y){
	return x.like>y.like;
}
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				b[i][j]=j;
			}
			if(a[i][1]<a[i][2]){swap(a[i][1],a[i][2]); swap(b[i][1],b[i][2]);}
			if(a[i][2]<a[i][3]){swap(a[i][2],a[i][3]); swap(b[i][2],b[i][3]);}
			if(a[i][1]<a[i][2]){swap(a[i][1],a[i][2]); swap(b[i][1],b[i][2]);}
			/*c[i][1]=a[i][1]-a[i][2];
			c[i][2]=a[i][2]-a[i][3];*/
		}
		int j[4];
		for(int i=1;i<=n;i++){
			ans+=a[i][1];
			z[b[i][1]]++;
			c[b[i][1]][j[b[i][1]]++]=a[i][1]-a[i][2];
		}
		for(int i=1;i<=3;i++){
			sort(c[i]+1,c[i]+1+j[i],cmp);
		}
		int z1[4]={0,1,2,3};
		if(z[1]<z[2]) swap(z1[1],z1[2]);
		if(z[2]<z[3]) swap(z1[2],z1[3]);
		if(z[1]<z[2]) swap(z1[1],z1[2]);
		for(int i=1;i<=3;i++){
			int x=z1[i];
			if(z[x]>(n/2)){
				for(int j=1;j<=z[x]-n/2;j++){
					ans-=c[x][j];
				}
			}
		}
		/*p tp[n+5];
		for(int i=1;i<=n;i++) tp[i]={i,a[i][1]};
		sort(tp+1,tp+1+n,cmp2);
		int b[4];
		for(int i=1;i<=n;i++){
			int k=tp[i].key;
			for(int j=1;j<=3;j++){
			    if(b[m[k][a[k][j]]]<n/2){
			    	b[m[k][a[k][j]]]++;
			    	ans+=a[k][j];
			    	break;
				}	
			}
		}
		cout<<'*'<<ans<<'\n';*/
	}
	return 0;
}
