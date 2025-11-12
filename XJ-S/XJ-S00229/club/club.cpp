#include<bits/stdc++.h>
using namespace std;
int T,n,bm[5];
long long ans; 
struct yg{
	int st,nd,rd,minn,bh1,bh2,bh3,ex,sx;
	int xb;
};
yg arr[100005];
bool cmp(yg x,yg y){
	if(x.sx-x.ex>y.sx-y.ex){
		return 1;
	}
	else if(x.sx-x.ex<y.sx-y.ex){
		return 0;
	}
	else{
		return x.ex-x.minn>y.ex-y.minn;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=bm[1]=bm[2]=bm[3]=0;
		int jx=n/2;
		for(int i=1;i<=n;i++){
			arr[i].xb=i;
			cin>>arr[i].st>>arr[i].nd>>arr[i].rd;
			if(arr[i].st<=arr[i].nd){
				if(arr[i].st<=arr[i].rd){
					arr[i].minn=arr[i].st;
					arr[i].bh1=1;
					if(arr[i].nd<=arr[i].rd){
						arr[i].bh2=2;
						arr[i].ex=arr[i].nd;
						arr[i].bh3=3;
						arr[i].sx=arr[i].rd;
					}else{
						arr[i].bh2=3;
						arr[i].ex=arr[i].rd;
						arr[i].bh3=2;
						arr[i].sx=arr[i].nd;
					}
				}else{
					arr[i].minn=arr[i].rd;
					arr[i].bh1=3;
					arr[i].bh2=1;
					arr[i].ex=arr[i].st;
					arr[i].bh3=2;
					arr[i].sx=arr[i].nd;
				}
			}else{
				if(arr[i].nd<=arr[i].rd){
					arr[i].minn=arr[i].nd;
					arr[i].bh1=2;
					if(arr[i].st<=arr[i].rd){
						arr[i].bh2=1;
						arr[i].ex=arr[i].st;
						arr[i].bh3=3;
						arr[i].sx=arr[i].rd;
					}else{
						arr[i].bh2=3;
						arr[i].ex=arr[i].rd;
						arr[i].bh3=1;
						arr[i].sx=arr[i].st;
					}
				}else{
					arr[i].minn=arr[i].rd;
					arr[i].bh1=3;
					arr[i].bh2=2;
					arr[i].ex=arr[i].nd;
					arr[i].bh3=1;	
					arr[i].sx=arr[i].st;				
				}
			}
		}
		//cout<<jx<<'\n';
		sort(arr+1,arr+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(bm[arr[i].bh3]<jx){
				//cout<<arr[i].xb<<' '<<arr[i].bh3<<' ';
				bm[arr[i].bh3]++;
				ans+=arr[i].sx;
			}
			else if(bm[arr[i].bh2]<jx){
				//cout<<arr[i].xb<<' '<<arr[i].bh2<<' ';
				bm[arr[i].bh2]++;
				ans+=arr[i].ex;
			}
			else{
				//cout<<arr[i].xb<<' '<<arr[i].bh1<<' ';
				bm[arr[i].bh1]++;
				ans+=arr[i].minn;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

