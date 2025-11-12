#include<bits/stdc++.h>
using namespace std;
int t,a[100010],b[100010],c[100010];
int s1=0,s2=0,s3=0;
struct d{
	int n1,n2;
}maxn[100010];
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	for(int i=1;i<=t;i++){
		int n,num=0;
		cin >>n;
		for(int j=1;j<=n;j++){
			cin >>a[j]>>b[j]>>c[j];
			if((a[j]>b[j])&&(a[j]>c[j])) {
				maxn[j].n1 =1;	
				maxn[j].n2 =a[j];
				s1++;	
				num+=a[j];
			}else if((b[j]>a[j])&&(b[j]>c[j])) {
				maxn[j].n1 =2;	
				maxn[j].n2 =b[j];
				s2++;
				num+=b[j];
			}else if((c[j]>a[j])&&(c[j]>b[j])){
				maxn[j].n1 =3;	
				maxn[j].n2 =c[j];
				s3++;
				num+=c[j];
			}
		}
		for(int l=1;l<=n;l++){
			for(int p=l+1;p<=n;p++){
				if(maxn[l].n2 <maxn[p].n2 ){
					int max1=maxn[l].n1 ,max2=maxn[l].n2 ;
					maxn[l].n1 =maxn[p].n1 ;
					maxn[l].n2 =maxn[p].n2 ;
					maxn[p].n1 =max1 ;
					maxn[p].n2 =max2 ;
				}
			}
		}
		if(s1*2<=n&&s2*2<=n&&s3*2<=n){
			cout <<num<<endl;
		} else if(s1*2>n){
			num=0;
			int s4=0;
			for(int k=1;k<=n;k++){
				
				if(maxn[k].n1=1&&maxn[k].n2>0&&s4*2<n){
					num+=maxn[k].n2;
					s4++;
				}else if(s4>=n/2){
					num+=max(b[k],c[k]);
				}
			}
			cout <<num<<endl;
		} else if(s2*2>n){
			num=0;
			int s4=0;
			
			for(int k=1;k<=n;k++){
				
				if(maxn[k].n1=2&&maxn[k].n2>0&&s4*2<n){
					num+=maxn[k].n2;
					s4++;
				}else if(s4>=n/2){
					num+=max(a[k],c[k]);
				}
			}
			cout <<num<<endl;
		}else if(s3*2>n){
			num=0;
			int s4=0;
			
			for(int k=1;k<=n;k++){
				
				if(maxn[k].n1=3&&maxn[k].n2>0&&s4*2<n){
					num+=maxn[k].n2;
					s4++;
				}else if(s4>=n/2){
					num+=max(b[k],c[k]);
				}
			}
			cout <<num<<endl;
		}
		s1=0,s2=0,s3=0;
	}
	return 0;
} 
