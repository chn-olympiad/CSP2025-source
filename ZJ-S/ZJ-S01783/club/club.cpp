#include<bits/stdc++.h>
using namespace std;
int n,i,T,ans,f1,f2,f3,a[100100][3];
struct no{
	int xh,c;
}b[100100],c[100100],d[100100];
bool cmp(no q,no h){
	return q.c>h.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		f1=f2=f3=0;
		for(i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}for(i=1;i<=n;i++){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]||a[i][1]>a[i][2]&&a[i][1]==a[i][3]||a[i][1]>a[i][3]&&a[i][1]==a[i][2]){
				b[++f1].xh=i;
				b[f1].c=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
				ans+=a[i][1];
			}
			else if(a[i][1]<a[i][2]&&a[i][2]>a[i][3]||a[i][2]>a[i][1]&&a[i][2]==a[i][3]){
				c[++f2].xh=i;
				c[f2].c=max(a[i][1]-a[i][2],a[i][3]-a[i][2]);
				ans+=a[i][2];
			}
			else{
				d[++f3].xh=i;
				d[f3].c=max(a[i][1]-a[i][3],a[i][2]-a[i][3]);
				ans+=a[i][3];
			}
		}
		if(f1>n/2){
			sort(b+1,b+f1+1,cmp);
			for(i=1;i<=f1-n/2;i++){
				ans+=b[i].c;
			}
		}else{
			if(f2>n/2){
				sort(c+1,c+f2+1,cmp);
				for(i=1;i<=f2-n/2;i++){
					ans+=c[i].c;
				}
			}else{
				sort(d+1,d+f3+1,cmp);
				for(i=1;i<=f3-n/2;i++){
					ans+=d[i].c;
				}
			}
		}cout<<ans<<"\n";
	}
	return 0;
}
