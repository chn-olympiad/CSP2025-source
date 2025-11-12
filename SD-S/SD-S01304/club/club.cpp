#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
long long a[200010],b[200010],c[200010],cnt1=0,cnt2=0,cnt3=0;
long long sum=0;
struct club{
	int a,b,c;
	char ma;
	bool j;
}d[200010];
bool cmp(club a1,club a2){
	if(a1.a!=a2.a) return a1.a>a2.a;
	else if(a1.b!=a2.b) return a1.b>a2.b;
	else return a1.c>a2.c;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			int maxx=max(max(d[i].a,d[i].b),d[i].c);
			if(maxx==d[i].a) d[i].ma=='a';
			else if(maxx=d[i].b) d[i].ma='b';
			else d[i].ma='c';
		}
		sort(d+1,d+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(d[i].a==0&&d[i].b==0){
				if(cnt3<n/2){
					sum+=d[i].c;
					cnt3++;
					d[i].j=1;
			}
			else if(d[i].a==0&&d[i].c==0){
				if(cnt2<n/2){
					sum+=d[i].b;
					cnt2++;
					d[i].j=1;
				}
			}
				else if(d[i].c==0&&d[i].b==0){
					if(cnt3<n/2){
						sum+=d[i].a;
						cnt1++;
						d[i].j=1;
				}
			}		
		}
		for(int i=1;i<=n;i++){
			if(d[i].j==1) continue;
			else if(d[i].ma=='b'){
				if(cnt2<n/2){
					sum+=d[i].b;
					cnt2++;
					d[i].j=1;
				}else if(d[i].a>d[i].c){
					if(cnt1<n/2){
						sum+=d[i].b;
						cnt2++;	
						d[i].j=1;
					}
				}
			}
			else if(d[i].ma=='c'){
				if(cnt3<n/2){
					sum+=d[i].c;
					cnt3++;
					if(d[i].a>d[i].b){
						if(cnt1<n/2){
							sum+=d[i].a;
							cnt1++;
						}else{
							sum+=d[i].b;
							cnt2++;
						}
					}
				}	
			}
		}
	}	
		cout<<sum<<"\n";
	}
	return 0;
}
