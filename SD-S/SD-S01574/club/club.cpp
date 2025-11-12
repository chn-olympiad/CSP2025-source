#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define xx first
#define yy second
const int N=1e5+10;
struct my{
	int x,y,z;
	int max_,max_id,min_;
	int b[5];//排序数组 
}a[N];
ll ans,cnt1,cnt2,cnt3;
bool cmp(my xx,my yy){
	return xx.max_>yy.max_;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--){
    	cnt1=0,cnt2=0,cnt3=0,ans=0;  
    	//cout<<ans<<" "<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
    	int n;cin>>n;
    	int s=n/2;//每部门最多分配 
    	for(int i=1;i<=n;++i){
    		cin>>a[i].x>>a[i].y>>a[i].z;
    		a[i].max_=max(a[i].x,max(a[i].y,a[i].z));
    		a[i].min_=min(a[i].x,min(a[i].y,a[i].z));
    		if(a[i].max_==a[i].x) a[i].max_id=1;
    		if(a[i].max_==a[i].y) a[i].max_id=2;
    		if(a[i].max_==a[i].z) a[i].max_id=3;
    		a[i].b[1]=a[i].x;
    		a[i].b[2]=a[i].y;
    		a[i].b[3]=a[i].z;
    		sort(a[i].b+1,a[i].b+4);
		}
    	sort(a+1,a+n+1,cmp);
    	for(int i=1;i<=n;++i){
    		if(a[i].max_id==1) {
    			if(cnt1<s){
    				cnt1++;
    				ans+=a[i].max_;
				}else if(a[i].max_<a[i-1].min_&&a[i].max_<a[i-1].b[2]){
					a[i-1].max_=a[i-1].b[2];
					--i;
				}else{
				    a[i].max_=a[i].b[2];
				    for(int i=1;i<3;++i){
    		            if(a[i].max_==a[i].y) a[i].max_id=2;
    		            if(a[i].max_==a[i].z) a[i].max_id=3;
				    }
				}
			}else{
				if(a[i].max_id==2) {
    			    if(cnt2<s){
    				    cnt2++;
    				    ans+=a[i].max_;
				    }else if(a[i].max_<a[i-1].min_&&a[i].max_<a[i-1].b[2]){
					    a[i-1].max_=a[i-1].b[2];
					    --i;
				    }else{
				        a[i].max_=a[i].b[2];
				        for(int i=1;i<3;++i){
    		                if(a[i].max_==a[i].z) a[i].max_id=3;
				        }
				    }
			    }else{
			    	if(a[i].max_id==3){
    				    cnt3++;
    	                ans+=a[i].max_;
			        }
				}
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}

