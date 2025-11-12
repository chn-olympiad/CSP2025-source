#include<bits/stdc++.h>
using namespace std;
int t,n,a[3],e[100010],x,p,ans;
struct node{
	int b,c,d,g;
}f[300010];
bool cmp(node i,node j){
	return i.d>j.d;
}
bool cmp2(node i,node j){
	if(i.g!=j.g)return i.g>j.g;
	return i.d>j.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
		p=ans=0;
		
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>x;
				f[p].b=i,f[p].c=j,f[p++].d=x;
			}sort(f+p-3,f+p,cmp);
			f[p-3].g=f[p-3].d-f[p-2].d;
			//f[p-2].g=f[p-2].d-f[p-1].d;
		}
		
		sort(f,f+3*n,cmp2);
		
		for(int i=0;i<3*n;i++){
			if(e[f[i].b] || a[f[i].c]==n/2)continue;
			ans+=f[i].d;
			e[f[i].b]=1,a[f[i].c]++;
		}
		cout<<ans<<"\n";
	}
    return 0;
}