#include<bits/stdc++.h>
using namespace std;
long long int t,n,a[100005][4],b1[100005],b2[100005],b3[100005],x[4],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int g=1;g<=t;g++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a[i][0]=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=a[i][0];
			if(a[i][0]==a[i][1]){
				x[1]++;
				b1[i]=max((a[i][2]-a[i][1]),(a[i][3]-a[i][1]));
			}else{
				if(a[i][0]==a[i][2]){
					x[2]++;
					b2[i]=max((a[i][1]-a[i][2]),(a[i][3]-a[i][2]));
				}else{
					if(a[i][0]==a[i][3]){
						x[3]++;
						b3[i]=max((a[i][1]-a[i][3]),(a[i][2]-a[i][3]));
					}
				}
			}
		}
		/*cout<<"ans="<<ans<<endl;
		for(int i=1;i<=n;i++){
			cout<<b1[i]<<" "<<b2[i]<<" "<<b3[i]<<endl;
		}*/
		if(x[1]>(n/2)){
			sort(b1+1,b1+n+1);
			for(int i=x[1];i>(n/2);i--){
				ans+=b1[i];
			}
		}
		if(x[2]>(n/2)){
			sort(b2+1,b2+n+1);
			for(int i=x[2];i>(n/2);i--){
				ans+=b2[i];
			}
		}
		if(x[3]>(n/2)){
			sort(b3+1,b3+n+1);
			for(int i=x[3];i>(n/2);i--){
				ans+=b3[i];
			}
		}
		for(int i=1;i<=n;i++){
			b1[i]=b2[i]=b3[i]=0;
		}
		cout<<ans<<endl;
		ans=0;
		x[1]=x[2]=x[3]=0;
	}
	return 0;
} 