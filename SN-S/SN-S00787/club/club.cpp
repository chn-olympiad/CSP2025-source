#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}p[100005];
int T,ans,bns,cns,dns[100005];
bool cmp(node x,node y){
	if(x.a>y.a){
		return x.a>y.a;
	}
	return x.b>y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0,bns=0,cns=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		sort(p+1,p+n+1,cmp);
		int aq=0,bq=0,cq=0;
		ans=0;
		for(int i=1;i<=n;i++){
			int mx=max(p[i].a,max(p[i].b,p[i].c));
			if(mx==p[i].a){
				if(aq<n/2){
					ans+=p[i].a;
					aq++;
				}
				else{
					int mxbc=max(p[i].b,p[i].c);
					if(mxbc==p[i].b){
						ans+=p[i].b;
						bq++;
					}
					else{
						ans+=p[i].c;
						cq++;
					}
				}
			}
			else if(mx==p[i].b){
				if(bq<n/2){
					ans+=p[i].b;
					bq++;
				}
				else{
					int mxac=max(p[i].a,p[i].c);
					if(mxac==p[i].a){
						ans+=p[i].a;							
						aq++;
					}
					else{
						ans+=p[i].c;
						cq++;
					}
				}
			}
			else if(mx==p[i].c){
				if(cq<n/2){
					ans+=p[i].c;
					cq++;
				}
				else{
					int mxab=max(p[i].a,p[i].b);
					if(mxab==p[i].a){
						ans+=p[i].a;
						aq++;
					}
					else{
						ans+=p[i].b;
						bq++;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				bns=0,aq=0,bq=0,cq=0;
				int mx=max(p[i].a,max(p[i].b,p[i].c));
				if(i==j){
					int mx=max(p[i].a,max(p[i].b,p[i].c));
					if(mx==p[i].a){
						int mxbc=max(p[i].b,p[i].c);
						if(mxbc==p[i].b){
							bns+=p[i].b;
							bq++;
						}
						else{
							bns+=p[i].c;
							cq++;
						}
					}
					else if(mx==p[i].b){
						int mxac=max(p[i].a,p[i].c);
						if(mxac==p[i].a){
							bns+=p[i].a;
							aq++;
						}
						else{
							bns+=p[i].c;
							cq++;
						}
					}
					else if(mx==p[i].c){
						int mxab=max(p[i].a,p[i].b);
						if(mxab==p[i].a){
							bns+=p[i].a;
							aq++;
						}
						else{
							bns+=p[i].b;
							bq++;
						}
					}
				}
				else{
					int mx=max(p[i].a,max(p[i].b,p[i].c));
					if(mx==p[i].a){
						if(aq<n/2){
							bns+=p[i].a;
							aq++;
						}
						else{
							int mxbc=max(p[i].b,p[i].c);
							if(mxbc==p[i].b){
								bns+=p[i].b;
								bq++;
							}
							else{
								bns+=p[i].c;
								cq++;
							}
						}
					}
					else if(mx==p[i].b){
						if(bq<n/2){
							bns+=p[i].b;
							bq++;
						}
						else{
							int mxac=max(p[i].a,p[i].c);
							if(mxac==p[i].a){
								bns+=p[i].a;
								aq++;
							}
							else{
								bns+=p[i].c;
								cq++;
							}
						}
					}
					else if(mx==p[i].c){
						if(cq<n/2){
							bns+=p[i].c;
							cq++;
						}
						else{
							int mxab=max(p[i].a,p[i].b);
							if(mxab==p[i].a){
								bns+=p[i].a;
								aq++;
							}
							else{
								bns+=p[i].b;
								bq++;
							}
						}
					}
				}
				cns=max(bns,cns);	
			} 
		}	
		cout<<max(ans,cns+3)<<endl;
	}
	return 0;
}
