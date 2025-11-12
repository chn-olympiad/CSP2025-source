#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0,maxn,a[100005],pa,b[100005],pb,c[100005],pc,mina[100005],minb[100005],minc[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		pa=0;
		pb=0;
		pc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]){
				minb[i]=b[i]-a[i];
				maxn=max(a[i],c[i]);
				if(maxn=a[i]){
					pa++;
					mina[i]=c[i]-a[i];
				}
				else{
					pc++;
					mina[i]=a[i]-c[i];
				}
				minc[i]=b[i]-c[i];
			}
			else{
				minb[i]=a[i]-b[i];
				maxn=max(b[i],c[i]);
				if(maxn=b[i]){
					pb++;
					minc[i]=c[i]-b[i];
				}
				else{
					pc++;
					minc[i]=b[i]-c[i];
				}
				mina[i]=a[i]-c[i];
			}
			ans+=maxn;
		}
		sort(mina+1,mina+1+n,cmp);
		sort(minb+1,minb+1+n,cmp);
		sort(minc+1,minc+1+n,cmp);
		if(pa>n/2){
			pa--;
			for(int i=1;i<=n;i++){
				if(mina[i]>minb[i]){
					pc++;
					ans+=minc[i];
				}
				else{
					pb++;
					ans+=minb[i];
				}
			}	
		}
		if(pb>n/2){
			pb--;
			for(int i=1;i<=n;i++){
				if(mina[i]>minc[i]){
					pc++;
					ans+=mina[i];
				}
				else{
					pa++;
					ans+=minc[i];
				}
			}	
		}
		if(pc>n/2){
			pc--;
			for(int i=1;i<=n;i++){
				if(minc[i]>minb[i]){
					pa++;
					ans+=minc[i];
				}
				else{
					pb++;
					ans+=minb[i];
				}
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/