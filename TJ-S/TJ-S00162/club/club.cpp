#include<bits/stdc++.h>
using namespace std;
int t;
int xa[100100],xb[100100],xc[100100];
long long a1,b2,c3;
long long n;
long long ans;
struct s{
	long long a,b,c;
}st[100100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		a1=0;
		b2=0;
		c3=0;
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>st[i].a>>st[i].b>>st[i].c;
		}
		for(int i=1;i<=n;i++){
			if(st[i].a>st[i].b){
				if(st[i].a>st[i].c){
					ans+=st[i].a;
					a1++;
					xa[a1]=i;
				}else{
					ans+=st[i].c;
					c3++;
					xc[c3]=i;
				}
			}else{
				if(st[i].b>st[i].c){
					ans+=st[i].b;
					b2++;
					xb[b2]=i;
				}else{
					ans+=st[i].c;
					c3++;
					xc[c3]=i;
				}
			}
		}
		if(a1>n/2){
			for(int i=1;i<=a1-n/2;i++){
				long long min=10000000;
				int zou=0;
				for(int j=1;j<=a1;j++){
					if(xa[j]!=-1){
						if(st[xa[j]].a-st[xa[j]].b<st[xa[j]].a-st[xa[j]].c){
							if(st[xa[j]].a-st[xa[j]].b<min){
								min=st[xa[j]].a-st[xa[j]].b;
								zou=j;
							}
						}else{
							if(st[xa[j]].a-st[xa[j]].c<min){
								min=st[xa[j]].a-st[xa[j]].c;
								zou=j;
							}
						}
					}
				}
				ans-=min;
				xa[zou]=-1;
			}
		}
		if(b2>n/2){
			for(int i=1;i<=b2-n/2;i++){
				long long min=10000000;
				int zou;
				for(int j=1;j<=b2;j++){
					if(xb[j]!=-1){
						if(st[xb[j]].b-st[xb[j]].a<st[xb[j]].b-st[xb[j]].c){
							if(st[xb[j]].b-st[xb[j]].a<min){
								min=st[xb[j]].b-st[xb[j]].a;
								zou=j;
							}
						}else{
							if(st[xb[j]].b-st[xb[j]].c<min){
								min=st[xb[j]].b-st[xb[j]].c;
								zou=j;
							}
						}
					}
				}
				ans-=min;
				xb[zou]=-1;
			}
		}
		if(c3>n/2){
			for(int i=1;i<=c3-n/2;i++){
				long long min=10000000;
				int zou;
				for(int j=1;j<=c3;j++){
					if(xc[j]!=-1){
						if(st[xc[j]].c-st[xc[j]].a<st[xc[j]].c-st[xc[j]].b){
							if(st[xc[j]].c-st[xc[j]].a<min){
								min=st[xc[j]].c-st[xc[j]].a;
								zou=j;
							}
						}else{
							if(st[xc[j]].c-st[xc[j]].b<min){
								min=st[xc[j]].c-st[xc[j]].b;
								zou=j;
							}
						}
					}
				}
				ans-=min;
				xc[zou]=-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
