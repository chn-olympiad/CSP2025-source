#include<bits/stdc++.h>
using namespace std;
struct um{
	int am,bm,cm;
}a[100005];
int ans,n,t,ay,by,cy;
bool def(um x,um y){
	return max(max(x.am,x.bm),x.cm)+max(max(x.am,x.bm),x.cm)+min(min(x.am,x.bm),x.cm)-x.am-x.bm-x.cm>max(max(y.am,y.bm),y.cm)+max(max(y.am,y.bm),y.cm)+min(min(y.am,y.bm),y.cm)-y.am-y.bm-y.cm;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d",&n);
		ay=0;
		by=0;
		cy=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i].am);
			scanf("%d",&a[i].bm);
			scanf("%d",&a[i].cm);
		}
		sort(a,a+n,def);
		for(int i=0;i<n;i++){
			if(a[i].am>=a[i].bm&&a[i].am>=a[i].cm&&ay<n/2){
				ay++;
				ans+=a[i].am;
			}
			else if(a[i].bm>=a[i].cm&&by<n/2){
				by++;
				ans+=a[i].bm;
			}
			else if(cy<n/2){
				cy++;
				ans+=a[i].cm;
			}
			else{
				if(a[i].am>a[i].bm){
					ay++;
					ans+=a[i].am;
				}
				else if(a[i].am<a[i].bm){
					by++;
					ans+=a[i].bm;
				}
				else{
					if(ay>=by){
						by++;
						ans+=a[i].bm;
					}
					else{
						ay++;
						ans+=a[i].am;
					}
				}
			}
		}
		printf("%d\n",ans);
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
