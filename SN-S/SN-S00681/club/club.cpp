//赵晗羽 SN-S00681 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct st{
	int m1,m2,m3;
}a[100005];
bool cmp(st x,st y){
	int xx=0,yy=0;
	if(x.m1==0)xx++;
	if(x.m2==0)xx++;
	if(x.m3==0)xx++;
	if(y.m1==0)yy++;
	if(y.m2==0)yy++;
	if(y.m3==0)yy++;		
	if(xx!=yy&&xx!=3)return xx>yy;
	else return max(x.m1,max(x.m2,x.m3))>max(y.m1,max(y.m2,y.m3));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int bj[4];
		for(int i=1;i<=3;i++)bj[i]=0;
		int n,s=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].m1>>a[i].m2>>a[i].m3;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].m1>=max(a[i].m2,a[i].m3)){
				if(bj[1]<n/2){
					s+=a[i].m1;
					bj[1]++;
				}else{
					if(a[i].m2>=a[i].m3){
						if(bj[2]<n/2){
							s+=a[i].m2;
							bj[2]++;
						}
					}else if(bj[3]<n/2){
						s+=a[i].m3;
						bj[3]++;						
					}
				}
			}
			if(a[i].m2>=max(a[i].m2,a[i].m1)){
				if(bj[2]<n/2){
					s+=a[i].m2;
					bj[2]++;
				}else{
					if(a[i].m1>=a[i].m3){
						if(bj[1]<n/2){
							s+=a[i].m1;
							bj[1]++;
						}
					}else if(bj[3]<n/2){
						s+=a[i].m3;
						bj[3]++;						
					}
				}
			}
			if(a[i].m3>=max(a[i].m2,a[i].m1)){
				if(bj[3]<n/2){
					s+=a[i].m3;
					bj[3]++;
				}else{
					if(a[i].m1>=a[i].m2){
						if(bj[1]<n/2){
							s+=a[i].m1;
							bj[1]++;
						}
					}else if(bj[2]<n/2){
						s+=a[i].m2;
						bj[2]++;						
					}
				}
			}
		}
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
