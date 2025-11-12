#include<bits/stdc++.h>
#define long long int
int t,n,numi,numj,numk,cnt,aa,bb,cc,alost,blost,clost;
int a[100005],b[100005],c[100005],a_b[100005],b_c[100005],a_c[100005],maxi[100005],ijk[100005];
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt=0;
		numi=0;
		numj=0;
		numk=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			a_b[i]=a[i]-b[i];
			b_c[i]=b[i]-c[i];
			a_c[i]=a[i]-c[i];
			maxi[i]=max(max(a[i],b[i]),c[i]);
			if(maxi[i]==a[i]){
				ijk[i]=1;
				numi++;
			}else if(maxi[i]==b[i]){
				ijk[i]=2;
				numj++;
			}else{
				ijk[i]=3;
				numk++;
			}		 
		}
		if(numi>n/2||numj>n/2||numk>n/2){
			aa=1;
			bb=1;
			cc=1;
			alost=n/2-numi;
			blost=n/2-numj;
			clost=n/2-numk;
			sort(a_b+1,a_b+n+1);
			sort(b_c+1,b_c+n+1);
			sort(a_c+1,a_c+n+1);
		}	
		if(numi<=n/2&&numj<=n/2&&numk<=n/2){
			for(int j=1;j<=n;j++) cnt+=max(max(a[j],b[j]),c[j]);
		}else if(numi>n/2){
			for(int j=1;j<=n;j++) cnt+=a[j];
			for(int j=alost;j<0;j++){
				if((a_b[bb]<a_c[cc]&&blost>0)||clost==0)
				{
					cnt-=a_b[bb];
					blost--;
				}else{
					cnt-=a_c[cc];
					clost--;
				}
			}
			
		}
		else if(numj>n/2){
			for(int j=1;j<=n;j++) cnt+=b[j];
			for(int j=blost;j<0;j++){
				if((a_b[n-aa+1]<b_c[cc]&&alost>0)||clost==0)
				{
					cnt-=a_b[n-aa+1]*-1;
					alost--;
				}else{
					cnt-=b_c[cc];
					clost--;
				}
			}
		}
		else if(numk>n/2){
			
			for(int j=1;j<=n;j++) cnt+=c[j];
			
			for(int j=clost;j<0;j++){
				if((b_c[n-bb+1]<a_c[n-aa+1]&&bb<=blost)||alost==0)
				{
					cnt-=b_c[n-bb+1]*-1;
					blost--;
				}else{
					cnt-=a_c[n-aa+1]*-1;
					alost--;
				}
			}	
		}
		cout<<cnt<<'\n';
	}
	return 0;
}

