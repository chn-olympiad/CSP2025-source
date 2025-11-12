//白祖铭，SN-S00553,宝塔区第一中学
#include<bits/stdc++.h>
using namespace std;
int t,fr[100010],se[100010],la[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n,a[100010][3],pop=0,a1=0,a2=0,a3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				a1++;
				pop+=a[i][1];
				fr[i]=-1;
				if(a[i][2]>=a[i][3]){
					se[i]=a[i][1]-a[i][2];
					la[i]=-1;
				}else{
					la[i]=a[i][1]-a[i][3];
					se[i]=-1;
				}
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				a2++;
				pop+=a[i][2];
				se[i]=-1;
				if(a[i][1]>=a[i][3]){
					fr[i]=a[i][2]-a[i][1];
					la[i]=-1;
				}else{
					la[i]=a[i][2]-a[i][3];
					fr[i]=-1;
				}
			}
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				a3++;
				pop+=a[i][3];
				la[i]=-1;
				if(a[i][1]>=a[i][2]){
					fr[i]=a[i][3]-a[i][1];
					se[i]=-1;
				}else{
					se[i]=a[i][3]-a[i][2];
					fr[i]=-1;
				}
			}
		}
		if(a1>n/2){
			sort(se+1,se+n+1);
			sort(la+1,la+n+1);
			for(int i=1;i<=n;i++){
				if(se[i]!=-1){
					a1--;
					pop-=se[i];
				} 
				if(la[i]!=-1){
					a1--;
					pop-=la[i];
				}
				if(a1<=n/2){
					break;
				}
			}
			
		}
		if(a2>n/2){
			sort(fr+1,fr+n+1);
			sort(la+1,la+n+1);
			for(int i=1;i<=n;i++){
				if(fr[i]!=-1){
					a2--;
					pop-=fr[i];
				} 
				if(la[i]!=-1){
					a2--;
					pop-=la[i];
				}
				if(a2<=n/2){
					break;
				}
			}
		}
		if(a3>n/2){
			sort(fr+1,fr+n+1);
			sort(se+1,se+n+1);
			for(int i=1;i<=n;i++){
				if(fr[i]!=-1){
					a3--;
					pop-=fr[i];
				} 
				if(se[i]!=-1){
					a3--;
					pop-=se[i];
				}
				if(a3<=n/2){
					break;
				}
			}
		}
		cout<<pop<<endl;
	}
	return 0;
} 
