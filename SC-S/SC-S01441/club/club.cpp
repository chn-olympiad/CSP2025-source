#include<bits/stdc++.h>
using namespace std;
int const N=1e5+5;
struct Yuan{
	int d,maxd;
}; 
struct Chenyuan{
	int d1,d2,d3;
	long long dz;
	Yuan d[4]={};
	bool operator <(Chenyuan b){
		return dz>b.dz;
	}
}a[N]={};
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int maxd1=0,maxd2=0,maxd3=0; 
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			a[i].dz=a[i].d1+a[i].d2+a[i].d3;
			if(a[i].d1>a[i].d2&&a[i].d1>a[i].d3){
				maxd1++; 
				a[i].d[1].maxd=a[i].d1,a[i].d[1].d=1;
				if(a[i].d2>a[i].d3){
					a[i].d[2].maxd=a[i].d2;
					a[i].d[2].d=2;
					a[i].d[3].maxd=a[i].d3;
					a[i].d[3].d=3;
				}else{
					a[i].d[2].maxd=a[i].d3;
					a[i].d[2].d=3;
					a[i].d[3].maxd=a[i].d2;
					a[i].d[3].d=2;
				}
			}else if(a[i].d2>a[i].d1&&a[i].d2>a[i].d3){
				maxd2++;
				a[i].d[1].maxd=a[i].d2,a[i].d[1].d=2;
				if(a[i].d1>a[i].d3){
					a[i].d[2].maxd=a[i].d1;
					a[i].d[2].d=1;
					a[i].d[3].maxd=a[i].d3;
					a[i].d[3].d=3;
				}else{
					a[i].d[2].maxd=a[i].d3;
					a[i].d[2].d=3;
					a[i].d[3].maxd=a[i].d1;
					a[i].d[3].d=1;
				}
			}else{
				maxd3++;
				a[i].d[1].maxd=a[i].d3,a[i].d[1].d=3;
				if(a[i].d1>a[i].d2){
					a[i].d[2].maxd=a[i].d1;
					a[i].d[2].d=1;
					a[i].d[3].maxd=a[i].d2;
					a[i].d[3].d=2;
				}else{
					a[i].d[2].maxd=a[i].d2;
					a[i].d[2].d=2;
					a[i].d[3].maxd=a[i].d1;
					a[i].d[3].d=1;
				}
			}
		}
		sort(a+1,a+n+1);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].d1<<" "<<a[i].d2<<" "<<a[i].d3<<":"<<a[i].dz<<"\n";
//		}
		long long ans=0,bian=n/2,d1=0,d2=0,d3=0;
		if(n==2){
			if(maxd1>bian||maxd2>bian||maxd3>bian){
				if(a[1].dz>a[2].dz){
					ans=a[2].d[1].maxd+a[1].d[2].maxd;
				}else{
					ans=a[1].d[1].maxd+a[2].d[2].maxd;
				}
				cout<<ans<<"\n";
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i].d[1].d==1){
				if(d1<bian){
					d1++;
					ans+=a[i].d[1].maxd;
				}else if(a[i].d[2].d==2){
					if(d2<bian){
						d2++;
						ans+=a[i].d[2].maxd;
					}else{
						d3++;
						ans+=a[i].d[3].maxd;
					}
				}else{
					if(d3<bian){
						d3++;
						ans+=a[i].d[2].maxd;
					}else{
						d2++;
						ans+=a[i].d[3].maxd;
					}
				}
			}else if(a[i].d[1].d==2){
				if(d2<bian){
					d2++;
					ans+=a[i].d[1].maxd;
				}else if(a[i].d[2].d==1){
					if(d1<bian){
						d1++;
						ans+=a[i].d[2].maxd;
					}else{
						d3++;
						ans+=a[i].d[3].maxd;
					}
				}else{
					if(d3<bian){
						d3++;
						ans+=a[i].d[2].maxd;
					}else{
						d1++;
						ans+=a[i].d[3].maxd;
					}
				}
			}else{
				if(d3<bian){
					d3++;
					ans+=a[i].d[1].maxd;
				}else if(a[i].d[2].d==1){
					if(d1<bian){
						d1++;
						ans+=a[i].d[2].maxd;
					}else{
						d2++;
						ans+=a[i].d[3].maxd;
					}
				}else{
					if(d2<bian){
						d2++;
						ans+=a[i].d[2].maxd;
					}else{
						d1++;
						ans+=a[i].d[3].maxd;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
		
	return 0;
} 