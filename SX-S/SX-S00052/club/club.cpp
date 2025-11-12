#include<bits/stdc++.h>
using namespace std;

struct student{
	int q;
	int w;
	int e;
}stu[100004];
bool cmp(student a,student s){
	return a.q>s.q;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,ans=0;
	cin>>t;
	for(int k=1;k<=t;k++){
		int z;
		bool a2=true,a3=true;
		cin>>z;
		for(int i=1;i<=z;i++){
			cin>>stu[i].q>>stu[i].w>>stu[i].e;
			if(stu[i].w!=0){
				a2=false;
			}if(stu[i].e!=0){
				a3=false;
			}
		}if(a2 && a3){
			sort(stu+1,stu+1+z,cmp);
			for(int i=1;i<=z/2;i++){
				ans+=stu[i].q;
			}cout<<ans<<endl;
			break;
		}if(z==2){
			int maxn=max(max(stu[1].q,stu[1].w),max(stu[1].w,stu[1].e)),setn;
			if(maxn==stu[1].q) setn=1;
			else if(maxn==stu[1].w) setn=2;
			else if(maxn==stu[1].e) setn=3;
			int maxm=max(max(stu[2].q,stu[2].w),max(stu[2].w,stu[2].e)),setm;
			if(maxm==stu[2].q) setm=1;
			else if(maxm==stu[2].w) setm=2;
			else if(maxm==stu[2].e) setm=3;
			if(setn!=setm){
				ans+=maxn+maxm;
				cout<<ans<<endl;
				break;
			}else{
				int maxn1,maxm1;
				if(setn==1){
					maxn1=max(stu[1].w,stu[1].e);
					maxm1=max(stu[2].e,stu[2].e);
				}if(setn==2){
					maxn1=max(stu[1].q,stu[1].e);
					maxm1=max(stu[2].q,stu[2].e);
				}if(setn==3){
					maxn1=max(stu[1].e,stu[1].w);
					maxm1=max(stu[2].e,stu[2].w);
				}ans=max(maxn+maxm1,maxm+maxn1);
				cout<<ans;
				break;
			}
		}if(z==4){
			int max2=-1;
			max2=max(stu[1].q+stu[2].q+stu[3].w+stu[4].e,max2);
			max2=max(stu[1].q+stu[2].q+stu[3].e+stu[4].w,max2);
			max2=max(stu[1].q+stu[2].w+stu[3].q+stu[4].e,max2);
			max2=max(stu[1].q+stu[2].w+stu[3].e+stu[4].q,max2);
			max2=max(stu[1].q+stu[2].e+stu[3].q+stu[4].w,max2);
			max2=max(stu[1].q+stu[2].e+stu[3].w+stu[4].q,max2);

			max2=max(stu[1].w+stu[2].q+stu[3].w+stu[4].e,max2);
			max2=max(stu[1].w+stu[2].q+stu[3].e+stu[4].w,max2);
			max2=max(stu[1].w+stu[2].w+stu[3].q+stu[4].e,max2);
			max2=max(stu[1].w+stu[2].w+stu[3].e+stu[4].q,max2);
			max2=max(stu[1].w+stu[2].e+stu[3].q+stu[4].w,max2);
			max2=max(stu[1].w+stu[2].e+stu[3].w+stu[4].q,max2);

			max2=max(stu[1].e+stu[2].q+stu[3].w+stu[4].e,max2);
			max2=max(stu[1].e+stu[2].q+stu[3].e+stu[4].w,max2);
			max2=max(stu[1].e+stu[2].w+stu[3].q+stu[4].e,max2);
			max2=max(stu[1].e+stu[2].w+stu[3].e+stu[4].q,max2);
			max2=max(stu[1].e+stu[2].e+stu[3].q+stu[4].w,max2);
			max2=max(stu[1].e+stu[2].e+stu[3].w+stu[4].q,max2);
			//情况2
			max2=max(stu[2].q+stu[1].q+stu[3].w+stu[4].e,max2);
			max2=max(stu[2].q+stu[1].q+stu[3].e+stu[4].w,max2);
			max2=max(stu[2].q+stu[1].w+stu[3].q+stu[4].e,max2);
			max2=max(stu[2].q+stu[1].w+stu[3].e+stu[4].q,max2);
			max2=max(stu[2].q+stu[1].e+stu[3].q+stu[4].w,max2);
			max2=max(stu[2].q+stu[1].e+stu[3].w+stu[4].q,max2);

			max2=max(stu[2].w+stu[1].q+stu[3].w+stu[4].e,max2);
			max2=max(stu[2].w+stu[1].q+stu[3].e+stu[4].w,max2);
			max2=max(stu[2].w+stu[1].w+stu[3].q+stu[4].e,max2);
			max2=max(stu[2].w+stu[1].w+stu[3].e+stu[4].q,max2);
			max2=max(stu[2].w+stu[1].e+stu[3].q+stu[4].w,max2);
			max2=max(stu[2].w+stu[1].e+stu[3].w+stu[4].q,max2);

			max2=max(stu[2].e+stu[1].q+stu[3].w+stu[4].e,max2);
			max2=max(stu[2].e+stu[1].q+stu[3].e+stu[4].w,max2);
			max2=max(stu[2].e+stu[1].w+stu[3].q+stu[4].e,max2);
			max2=max(stu[2].e+stu[1].w+stu[3].e+stu[4].q,max2);
			max2=max(stu[2].e+stu[1].e+stu[3].q+stu[4].w,max2);
			max2=max(stu[2].e+stu[1].e+stu[3].w+stu[4].q,max2);
   //情况3
			max2=max(stu[3].q+stu[1].q+stu[2].w+stu[4].e,max2);
			max2=max(stu[3].q+stu[1].q+stu[2].e+stu[4].w,max2);
			max2=max(stu[3].q+stu[1].w+stu[2].q+stu[4].e,max2);
			max2=max(stu[3].q+stu[1].w+stu[2].e+stu[4].q,max2);
			max2=max(stu[3].q+stu[1].e+stu[2].q+stu[4].w,max2);
			max2=max(stu[3].q+stu[1].e+stu[2].w+stu[4].q,max2);

			max2=max(stu[3].w+stu[1].q+stu[2].w+stu[4].e,max2);
			max2=max(stu[3].w+stu[1].q+stu[2].e+stu[4].w,max2);
			max2=max(stu[3].w+stu[1].w+stu[2].q+stu[4].e,max2);
			max2=max(stu[3].w+stu[1].w+stu[2].e+stu[4].q,max2);
			max2=max(stu[3].w+stu[1].e+stu[2].q+stu[4].w,max2);
			max2=max(stu[3].w+stu[1].e+stu[2].w+stu[4].q,max2);

			max2=max(stu[3].e+stu[1].q+stu[2].w+stu[4].e,max2);
			max2=max(stu[3].e+stu[1].q+stu[2].e+stu[4].w,max2);
			max2=max(stu[3].e+stu[1].w+stu[2].q+stu[4].e,max2);
			max2=max(stu[3].e+stu[1].w+stu[2].e+stu[4].q,max2);
			max2=max(stu[3].e+stu[1].e+stu[2].q+stu[4].w,max2);
			max2=max(stu[3].e+stu[1].e+stu[2].w+stu[4].q,max2);
			//情况4
			max2=max(stu[4].q+stu[1].q+stu[2].w+stu[3].e,max2);
			max2=max(stu[4].q+stu[1].q+stu[2].e+stu[3].w,max2);
			max2=max(stu[4].q+stu[1].w+stu[2].q+stu[3].e,max2);
			max2=max(stu[4].q+stu[1].w+stu[2].e+stu[3].q,max2);
			max2=max(stu[4].q+stu[1].e+stu[2].q+stu[3].w,max2);
			max2=max(stu[4].q+stu[1].e+stu[2].w+stu[3].q,max2);

			max2=max(stu[4].w+stu[1].q+stu[2].w+stu[3].e,max2);
			max2=max(stu[4].w+stu[1].q+stu[2].e+stu[3].w,max2);
			max2=max(stu[4].w+stu[1].w+stu[2].q+stu[3].e,max2);
			max2=max(stu[4].w+stu[1].w+stu[2].e+stu[3].q,max2);
			max2=max(stu[4].w+stu[1].e+stu[2].q+stu[3].w,max2);
			max2=max(stu[4].w+stu[1].e+stu[2].w+stu[3].q,max2);

			max2=max(stu[4].e+stu[1].q+stu[2].w+stu[3].e,max2);
			max2=max(stu[4].e+stu[1].q+stu[2].e+stu[3].w,max2);
			max2=max(stu[4].e+stu[1].w+stu[2].q+stu[3].e,max2);
			max2=max(stu[4].e+stu[1].w+stu[2].e+stu[3].q,max2);
			max2=max(stu[4].e+stu[1].e+stu[2].q+stu[3].w,max2);
			max2=max(stu[4].e+stu[1].e+stu[2].w+stu[3].q,max2);

			cout<<max2<<endl;
		}
	}return 0;
}