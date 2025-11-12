#include <bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int c[100010];
int d[100010];
int d1[100010];
int d2[100010];
int q=0;
int w=0;
int e=0;
int gs1,gs2,gs3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	int zongshu=0;
	cin >> t;
	for(int o=1;o<=t;o++){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			cin >> b[i];
			cin >> c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				gs1++;
				d[gs1]=a[i];
				zongshu=zongshu+a[i];
			}
			if(b[i]>=a[i]&&b[i]>=c[i]){
				gs2++;
				d1[gs2]=b[i];
				zongshu=zongshu+b[i];
			}
			if(c[i]>=a[i]&&c[i]>=b[i]){
				gs3++;
				d2[gs3]=c[i];
				zongshu=zongshu+c[i];
			}
		}
		if(gs1>n/2){
			sort(d,d+gs1+1);
			q=d[gs1-n/2+1];
		}
		if(gs2>n/2){
			sort(d1,d1+gs2+1);
			w=d1[gs2-n/2+1];
		}
		if(gs3>n/2){
			sort(d2,d2+gs3+1);
			e=d2[gs3-n/2+1];
		}	
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				if(a[i]<q){
					if(d[i]>c[i]){
						zongshu=zongshu-a[i]+b[i];
					}
					else{
						zongshu=zongshu-a[i]+c[i];						
					}
					
				}
			}
			if(b[i]>=a[i]&&b[i]>=c[i]){
				if(b[i]<w){
					if(a[i]>c[i]){
						zongshu=zongshu-b[i]+a[i];
					}
					else{
						zongshu=zongshu-b[i]+c[i];						
					}
					
				}
			}
			if(c[i]>=a[i]&&c[i]>=b[i]){
				if(c[i]<e){
					if(d[i]>a[i]){
						zongshu=zongshu-c[i]+b[i];
					}
					else{
						zongshu=zongshu-c[i]+a[i];						
					}
					
				}
			}
		}
		cout <<zongshu<<endl;
		zongshu=0;	
		q=0;
		w=0;
		e=0;
		gs1=0;
		gs2=0;
		gs3=0;
		for(int i=1;i<=n;i++){
			d[i]=0;
			d1[i]=0;
			d2[i]=0;
		}
	}
	
	
	return 0;
}
