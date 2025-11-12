#include<bits/stdc++.h>
using namespace std;
int n,used[4];
long long ans;
struct peo{
	int a,b,c;
	int val;
}a[100010];
int max3(int a,int b,int c){
	return max(a,max(b,c));
}
int min3(int a,int b,int c){
	return min(a,min(b,c));
}
int mid(int a,int b,int c){
	int p[3]={a,b,c};
	sort(p,p+3);
	return p[1];
}
bool cmp(peo aa,peo bb){
	if(aa.val==bb.val) return max3(aa.a,aa.b,aa.c)>max3(bb.a,bb.b,bb.c);
	return aa.val>bb.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		memset(used,0,sizeof(used));
		cin>>n;
		for(int i=1;i<=n;i++){
			//cin>>a[i].a>>a[i].b>>a[i].c;
			scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
			a[i].val=max3(a[i].a,a[i].b,a[i].c)-mid(a[i].a,a[i].b,a[i].c);
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			int max123=max3(a[i].a,a[i].b,a[i].c);
			int mid123=mid(a[i].a,a[i].b,a[i].c);
			int min123=min3(a[i].a,a[i].b,a[i].c);
			int maxi,midi,mini;
			if(max123==a[i].a){
				if(mid123==a[i].b){
					maxi=1;midi=2,mini=3;
				}else{
					maxi=1;midi=3,mini=2;
				}
			}else if(max123==a[i].b){
				if(mid123==a[i].a){
					maxi=2;midi=1,mini=3;
				}else{
					maxi=2;midi=3,mini=1;
				}
			}else{
				if(mid123==a[i].a){
					maxi=3;midi=1,mini=2;
				}else{
					maxi=3;midi=2,mini=1;
				}
			}
			if(used[maxi]<n/2){
				ans+=max123;
				used[maxi]++;
			}else if(used[midi]<n/2){
				ans+=mid123;
				used[midi]++;
			}else{
				ans+=min123;
				used[mini]++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
