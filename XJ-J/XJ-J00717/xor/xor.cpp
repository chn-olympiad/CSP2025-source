#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;
int a[N],n,k,ans=0,flag=0;

 

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	//特殊性质A 
	if(!flag){
		cout<<0;
		return 0;
	}
	//找左1起点
	for(int l_1=1;l_1<=n;l_1++){
		//找左2起点
		for(int l_2=l_1;l_2<=n;l_2++){
			//找右1终点
			for(int r_1=l_1;r_1<=l_2;r_1++){
				//找右2起点
				for(int r_2=r_1;r_2<=n;r_2++){
					if(l_1<l_2 && r_1<r_2){
						//符合条件的区间，开始计算
						int cnt1=0,cnt2=0;
						for(int i=l_1;i<=r_1;i++){
							cnt1=cnt1 xor a[i];
						} 
						for(int i=l_2;i<=r_2;i++){
							cnt2=(cnt2 xor a[i]);
						} 
//						cout<<l_1<<" "<<r_1<<":"<<l_2<<" "<<r_2<<"xor"<<cnt1<<":"<<cnt2<<"\n";
						if(cnt1==cnt2 && cnt1==k){
//							cout<<"可行"<<l_1<<" "<<r_1<<":"<<l_2<<" "<<r_2<<"xor"<<cnt1<<":"<<cnt2<<"\n";
							ans=max(ans,max(abs(l_1-r_1),abs(l_2-r_2)));
//							cout<<"新答案:"<<ans<<"\n";
						}
					}
				} 
			} 
		} 
	} 
	cout<<ans;
	return 0;
}

