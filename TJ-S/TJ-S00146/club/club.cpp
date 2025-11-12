#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int sum;
int c1[10005];
int c2[10005];
int c3[10005];
int cnt[4];
int c1md[10005];
int c2md[10005];
int c3md[10005];
int maxn , maxb;
void max3(int a,int b,int c){
	maxn=0;
	maxb=0;
	if(a>=b && a>=c){
		maxn=a;
		maxb=1;
	}
	if(b>=a && b>=c){
		maxn=b;
		maxb=2;
	}
	if(c>=a && c>=b){
		maxn=c;
		maxb=3;
	}	 

}
void max2(int a,int b){
	maxn=0;
	maxb=0;
	if(a>=b){
		maxn=a;
		maxb=1;
	}
	else{
		maxn=b;
		maxb=2;
	} 

}
//int mymove(int mr,int mc){
//	for(int i=1;i<=mrli++){
//		for(int j=1;j<=n;j++){
//			
//		}
//	}
//	
//	
//	
//	
//}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin >> t;
	int a=1;
	int b=1;
	int c=1;
	for(int i=0;i<t;i++){
		cin >> n;
		int t=1;
		for(int j=1;j<=n;j++){					
			cin >> c1[j] >> c2[j] >> c3[j];
			max3(c1[j],c2[j],c3[j]);
			sum+=maxn;
			cnt[maxb]++;
//			if(maxb==1){
//				c1md[a]=j;
//				a++;
//			}
//			if(maxb==2){
//				c2md[b]=j;
//				b++;
//			}
//			if(maxb==3){
//				c3md[c]=j;
//				c++;
//			}
		}
//		for(int k=1;k<=3;k++){
//			if(cnt[k]>n/2){
//				cout << mymove(cnt[k]-n/2,k) ;
//			}
//			else{
		cout << sum ;
//				continue;
//			}
//		}
//		
	}
	
	
	return 0;
}
