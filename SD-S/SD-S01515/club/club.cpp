#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int ans;
bool cmp(int a,int b){
	return a>b;
}
int a1,b1,c1;
int a2,b2,c2;
int a[1000]; 
int b[1000];
int c[1000];
int compare(int l,int m,int n){
	int maxn=l;
	if(m>maxn) maxn=m;
	if(n>maxn) maxn=n;
	return maxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;a1=0;b1=0;c1=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			scanf("%d",&b[i]);
			scanf("%d",&c[i]);
		}
		sort(a,a+n,cmp);
		sort(b,b+n,cmp);
		sort(c,c+n,cmp);
		for(int i=0;i<n;i++){
			if(compare(a[i],b[i],c[i])==a[i]&&a2<n/2){
				a1+=a[i];
				a2++;
			}
			if(compare(a[i],b[i],c[i])==b[i]&&a[i]!=b[i]&&b2<n/2){
				b1+=b[i];
				b2++;
			}
			if(compare(a[i],b[i],c[i])==a[i]&&a[i]!=c[i]&&c2<n/2){
				c1+=c[i];
				c2++;
			}
		}
	
		for(int i=0;i<n/2;i++){
			ans=a1+b1+c1;
		}
		
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
