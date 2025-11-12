#include<bits/stdc++.h>
using namespace std;
int t,n,zb,aa[5],ans=0;
struct st{
	int a1,a2,a3;
}cy[100005];
bool pd1(st a,st b){
	return max(a.a2-a.a1,a.a3-a.a1)>max(b.a2-b.a1,b.a3-b.a1);
}bool pd2(st a,st b){
	return max(a.a1-a.a2,a.a3-a.a2)>max(b.a1-b.a2,b.a3-b.a2);
}bool pd3(st a,st b){
	return max(a.a2-a.a3,a.a1-a.a3)>max(b.a2-b.a3,b.a1-b.a3);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;aa[1]=aa[2]=aa[3]=0;ans=0;zb=1;
		for(int i=1;i<=n;i++){
			cin>>cy[i].a1>>cy[i].a2>>cy[i].a3;
			if(cy[i].a1>=cy[i].a2&&cy[i].a1>=cy[i].a3){
				aa[1]++;
			}if(cy[i].a2>=cy[i].a1&&cy[i].a2>=cy[i].a3){
				aa[2]++;
			}if(cy[i].a3>=cy[i].a1&&cy[i].a3>=cy[i].a2){
				aa[3]++;
			}
		}if(aa[1]>=aa[2]&&aa[1]>=aa[3]){
			sort(cy+1,cy+n+1,pd1);
			while(max(cy[zb].a2-cy[zb].a1,cy[zb].a3-cy[zb].a1)>0||zb<=(n/2)){
				ans+=max(cy[zb].a2,cy[zb].a3);
				zb++;
			}for(int i=zb;i<=n;i++){
				ans+=cy[i].a1;
			}
		}else if(aa[2]>=aa[3]){
			sort(cy+1,cy+n+1,pd2);
			while(max(cy[zb].a1-cy[zb].a2,cy[zb].a3-cy[zb].a2)>0||zb<=(n/2)){
				ans+=max(cy[zb].a1,cy[zb].a3);
				zb++;
			}for(int i=zb;i<=n;i++){
				ans+=cy[i].a2;
			}
		}else{
			sort(cy+1,cy+n+1,pd3);
			while(max(cy[zb].a2-cy[zb].a3,cy[zb].a1-cy[zb].a3)>0||zb<=(n/2)){
				ans+=max(cy[zb].a2,cy[zb].a1);
				zb++;
			}for(int i=zb;i<=n;i++){
				ans+=cy[i].a3;
			}
		}cout<<ans<<endl;
	}
}
