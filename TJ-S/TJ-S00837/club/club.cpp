#include <bits/stdc++.h>
using namespace std;
int t,n,cnt1,cnt2,cnt3,p[100005],ans,sum;
bool fl;
struct inf{
	int x,y,v;
}a[300005];
bool cmp(inf xx,inf yy){
	if(xx.v!=yy.v) return xx.v>yy.v;
	else return xx.x<yy.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
   			for(int k=0;k<3;k++){
   				cin>>a[j*3+k].v;
   				a[j*3+k].x=k;
   				a[j*3+k].y=j;
			}
		}
		sort(a,a+n*3,cmp);
		int j=0;
		while(ans<n&&j<n*3){
			fl=1;
			for(int k=0;k<ans;k++){
				if(p[k]==a[j].y){
					fl=0;
					break;
				}
			}
			if(fl==0) continue;
			else{
				if(cnt1+1<=n/2&&a[j].x==0) cnt1++,p[ans++]=a[j].y,sum+=a[j].v;
				else if(cnt2+1<=n/2&&a[j].x==1) cnt2++,p[ans++]=a[j].y,sum+=a[j].v;
				else if(cnt3+1<=n/2&&a[j].x==2) cnt3++,p[ans++]=a[j].y,sum+=a[j].v;
			}
			j++;
		}	
		cout<<sum<<endl;
		for(int j=0;j<ans;j++){
			p[j]=0;
		}
		cnt1=0,cnt2=0,cnt3=0;
		ans=0;
		sum=0;
		j=0;
	}
	return 0;
}
