#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ll flag1=0,flag2=0,flag3=0;
		ll n,ans=0,cnt;
		cin>>n;
		cnt=n/2;
		for(ll i=1;i<=n;i++){
			int a,b,c,maxx=-1;
			cin>>a>>b>>c;
			maxx=max(a,b);
			maxx=max(maxx,c);
			if(maxx==a && flag1<cnt){
				flag1++;
				ans+=maxx;
										
			}else if(maxx==b && flag2<cnt){
				flag2++;
				ans+=maxx;										
			}else if(maxx==c && flag3<cnt){
				flag3++;
				ans+=maxx;
										
			}else{
				if(maxx==a){
					maxx=max(b,c);
					if(maxx==b && flag2<cnt){
						ans+=maxx;
						flag2++;
												
					}else if(maxx==c && flag3<cnt){
						ans+=maxx;
						flag3++;
												
					}else if(maxx==c && flag3==cnt){
						ans+=b;
						flag2++;
												
					}else if(maxx==b&&flag2==cnt){
						ans+=c;
						flag3++;
												
					}
				}else if(maxx==b){
					maxx=max(a,c);
					if(maxx==a && flag1<cnt){
						ans+=maxx;
						flag1++;
												
					}else if(maxx==c && flag3<cnt){
						ans+=maxx;
						flag3++;
												
					}else if(maxx==c && flag3==cnt){
						ans+=a;
						flag1++;
												
					}else if(maxx==a&&flag1==cnt){
						ans+=c;
						flag3++;
												
					}
				}else if(maxx==c){
					maxx=max(b,a);
					if(maxx==b && flag2<cnt){
						ans+=maxx;
						flag2++;
												
					}else if(maxx==a && flag1<cnt){
						ans+=maxx;
						flag1++;
											
					}else if(maxx==a && flag1==cnt){
						ans+=b;
						flag2++;
											
					}else if(maxx==b&&flag2==cnt){
						ans+=a;
						flag1++;
											
					}
				}
			}
		}
		cout/*<<"ans:"*/<<ans<<endl;
		
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
