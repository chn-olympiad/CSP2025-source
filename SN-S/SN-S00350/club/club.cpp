//李明轩 SN-S00350 西安铁一中滨河高级中学 
#include<bits/stdc++.h>
using namespace std;
int t,n[7];
struct node{
	int x,y,z;
};
struct ln{
	int maxn,midn,g;
};
node m[100005];
ln mm[100005];
bool cmp(ln x,ln y){
	if(x.maxn<y.maxn)return 1;
	else return 0;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
    cin>>t;
    int ans,s1,s2,s3;
    for(int i=1;i<=t;i++){
    	cin>>n[i];
		for(int j=1;j<=n[i];j++) {
			cin>>m[j].x>>m[j].y>>m[j].z;
    	    int s;
		    s=max(m[j].x,m[j].y);
	        mm[j].maxn=max(m[j].z,s);
		    if(mm[j].maxn==m[j].x){
		    	mm[j].midn=max(m[j].z,m[j].y);
		    	mm[j].g=1;
			} 
		    if(mm[j].maxn==m[j].y) {
		    	mm[j].midn=max(m[j].z,m[j].x);
		    	mm[j].g=2;
			}
		    if(mm[j].maxn==m[j].z){
		    	mm[j].midn=max(m[j].x,m[j].y);
		    	mm[j].g=3;
			} 
		}
		sort(mm+1,mm+1+n[i],cmp);			
		int p=0;
		while(p<=n[i]){
			p++;
			if(s1<n[i]/2&&s2<n[i]/2&&s3<n[i]/2){
			    ans+=mm[p].maxn;
		        if(mm[p].g=1) s1++;
		        if(mm[p].g=2) s2++;
		        if(mm[p].g=3) s3++;
			}
		    if(s1>=n[i]/2||s2>=n[i]/2||s3>=n[i]/2){
		    	ans+=mm[p].midn;
			}
		}
		cout<<ans<<endl;
	    ans=0;
	}
	return 0;
}
