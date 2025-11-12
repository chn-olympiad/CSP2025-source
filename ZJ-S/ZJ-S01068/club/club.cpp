#include<bits/stdc++.h>
using namespace std;
int t,n,t1,t2,t3;
long long ans;
struct tt{
	int a,b,c,mx,k;
}f[100005];
bool cmp(tt x,tt y){
	if(x.k==y.k)return x.mx>y.mx;
	return x.k>y.k;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int g=1;g<=t;g++){
		t1=t2=t3=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
			f[i].mx=max(f[i].a,max(f[i].b,f[i].c));
			f[i].k=2*f[i].mx-f[i].a-f[i].b-f[i].c;
		}
		sort(f+1,f+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(f[i].mx==f[i].a){
				if(t1+1>(n/2)){
					ans+=max(f[i].b,f[i].c);
					continue;
				}
				t1++;
				ans+=f[i].mx;
			}
			else if(f[i].mx==f[i].b){
				if(t2+1>(n/2)){
					ans+=max(f[i].a,f[i].c);
					continue;
				}
				t2++;
				ans+=f[i].mx;
			}
			else {
				if(t3+1>(n/2)){
					ans+=max(f[i].a,f[i].b);
					continue;
				}
				t3++;
				ans+=f[i].mx;
			}
		}
		cout<<ans<<"\n";
	}
}
