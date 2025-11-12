#include<bits/stdc++.h>
using namespace std;
struct nd{
	int a,b;
	int an,bn;
};
nd st[100001];
int n;
nd zz[4];
int t;
int v[4];
bool cmpz(nd x,nd y){
	return x.a>y.a;
}
bool cmp(nd x,nd y){
	return x.a-x.b>y.a-y.b;
}
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>zz[j].a;
				zz[j].an=j;
			}
			sort(zz+1,zz+4,cmpz);
			st[i]={zz[1].a,zz[2].a,zz[1].an,zz[2].an};
		}
		sort(st+1,st+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(v[st[i].an]<n/2){
				v[st[i].an]++;
				ans=ans+st[i].a;
			}
			else{
				v[st[i].bn]++;
				ans+=st[i].b;
			}
		}
		cout<<ans<<"\n";
		v[1]=0;
		v[2]=0;
		v[3]=0;
	}
}
