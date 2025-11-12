#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a,b,c,k1,k2;
	bool operator <(node z)const{
		if(k1!=z.k1)return k1>z.k1;
		else return k2>z.k2;
	}
}f[100001];
int t,n;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int a1=0,b1=0,c1=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
			if(f[i].a>=f[i].b&&f[i].a>=f[i].c){
				f[i].k1=f[i].a-max(f[i].b,f[i].c);
				f[i].k2=f[i].a-min(f[i].b,f[i].c);
			}
			else if(f[i].b>=f[i].a&&f[i].b>=f[i].c){
				f[i].k1=f[i].b-max(f[i].a,f[i].c);
				f[i].k2=f[i].b-min(f[i].a,f[i].c);
			}
			else if(f[i].c>=f[i].a&&f[i].c>=f[i].b){
				f[i].k1=f[i].c-max(f[i].a,f[i].b);
				f[i].k2=f[i].c-min(f[i].a,f[i].b);
			}
		}
		sort(f+1,f+n+1);
		for(int i=1;i<=n;i++){
			int x=max(f[i].a,max(f[i].b,f[i].c));
			if(x==f[i].a){
				if(a1<n/2){
					ans+=f[i].a;
					a1++;
				}
				else{
					x-=f[i].k1;
					if(x==f[i].b){
						if(b1<=n/2){
							ans+=f[i].b;
							b1++;
						}
						else{
							ans+=f[i].c;
							c1++;
						}
					}
					if(x==f[i].c){
						if(c1<=n/2){
							ans+=f[i].c;
							c1++;
						}
						else{
							ans+=f[i].b;
							b1++;
						}
					}
				}
			}
			else if(x==f[i].b){
				if(b1<n/2){
					ans+=f[i].b;
					b1++;
				}
				else{
					x-=f[i].k1;
					if(x==f[i].a){
						if(a1<=n/2){
							ans+=f[i].a;
							a1++;
						}
						else{
							ans+=f[i].c;
							c1++;
						}
					}
					if(x==f[i].c){
						if(c1<=n/2){
							ans+=f[i].c;
							c1++;
						}
						else{
							ans+=f[i].a;
							a1++;
						}
					}
				}
			}
			else if(x==f[i].c){
				if(c1<n/2){
					ans+=f[i].c;
					c1++;
				}
				else{
					x-=f[i].k1;
					if(x==f[i].a){
						if(a1<=n/2){
							ans+=f[i].a;
							a1++;
						}
						else{
							ans+=f[i].b;
							b1++;
						}
					}
					if(x==f[i].b){
						if(b1<=n/2){
							ans+=f[i].b;
							b1++;
						}
						else{
							ans+=f[i].a;
							a1++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
