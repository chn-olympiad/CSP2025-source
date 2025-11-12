#include<bits/stdc++.h>
using namespace std;
int const N=1e5+10;
struct st{
	int s,g;
}a[N];
st b[N];
st c[N];
bool p[N];
int t=0;
int a1,b1,c1;
bool cmp(st x,st y){
	return x.s>y.s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int sum=0;
		int n=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].s>>b[i].s>>c[i].s;
			a[i].g=i;
			b[i].g=i;
			c[i].g=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int k=1;k<=n/3;k++){
			int aa;
			for(int i=1;i<=n;i++){
				if(p[a[i].g]==0){
					p[a[i].g]=1;
					sum+=a[i].s;
					break;
				}
			}	
			for(int j=1;j<=n;j++){
				if(p[b[j].g]==0){
					p[b[j].g]=1;
					sum+=b[j].s;
					aa=b[j].s;//--------------------------------
					break;
				}
			}
			for(int l=1;l<=n;l++){
				if(p[c[l].g]==0){
					p[c[l].g]=1;
					sum+=c[l].s;
					break;
				}
			}
			//cout<<"_______________________"<<sum<<" "<<aa<<"\n";
		}
		if(n%3==1){
				int z1=0;
				int i,j,l;
				for(i=1;i<=n;i++){
					if(p[a[i].g]==0&&a[i].s!=0){
						p[a[i].g]=1;
						z1=a[i].s;
						break;
					}
				}	
				for(j=1;j<=n;j++){
					if(p[b[j].g]==0&&b[j].s!=0){
						if(z1<b[j].s){
							p[a[i].g]=0;
							p[b[j].g]=1;
							z1=b[j].s;
						}
						break;
					}
				}
				for(l=1;l<=n;l++){
					if(p[c[l].g]==0&&c[l].s!=0){
						if(z1<c[l].s){
							p[b[j].g]=0;
							p[c[l].g]=1;
							z1=c[l].s;
						}
						break;
					}
				}
				sum+=z1;
				//cout<<"_________1______________"<<z1<<"\n";
		}
		else if(n%3==2){
				int z1=0,z2=0;
				int i,j,l;
				for(i=1;i<=n;i++){
					if(p[a[i].g]==0&&a[i].s!=0){
						p[a[i].g]=1;
						z1=a[i].s;
						break;
					}
				}	
				for(j=1;j<=n;j++){
					if(p[b[j].g]==0&&b[j].s!=0){
						p[b[j].g]=1;
						z2=b[j].s;
						break;
					}
				}
				for(l=1;l<=n;l++){
					if(p[c[l].g]==0&&c[l].s!=0){
						if(z1<c[l].s&&z2>c[l].s||z1<c[l].s&&z2<c[l].s&&(z1<=z2)){
							p[a[i].g]=0;
							p[c[l].g]=1;
							z1=c[l].s;
							break;
						}
						if(z1>c[l].s&&z2<c[l].s||z1<c[l].s&&z2<c[l].s&&(z1>z2)){
							p[b[j].g]=0;
							p[c[l].g]=1;
							z2=c[l].s;
							break;
						}
					}
				}
				sum+=z1+z2;
				//cout<<"_________2______________"<<z1<<" "<<z2<<"\n";
		}
		cout<<sum<<"\n";
	}
	return 0;
}