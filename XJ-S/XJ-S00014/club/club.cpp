#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct ren{
	ll s,biao,ss;//s表示满意度,biao表示社团编号 
};
bool cmp(ren z,ren zz){
	return z.s>zz.s;
}
ren sss1[100005];
ll n,t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);//别忘了删除注释！！！ 
	scanf("%lld",&t);
	while(t--){
		memset(sss1,0,sizeof(sss1));
		cin>>n;
		ll n1=n,n2=0,n3=0,s1,s2,ans=0,a1=0,a2=0,a3=0;
		for(ll i=1;i<=n;i++){
			cin>>a1>>a2>>a3;
			ans+=a1;
			s1=a2-a1;
			s2=a3-a1;
			sss1[i].s=max(s1,s2);
			sss1[i].ss=min(s1,s2);
			if(s1>=s2){
				sss1[i].biao=2;
			}
			else{
				sss1[i].biao=3;
			}
		}
		sort(sss1+1,sss1+n+1,cmp);
		
		for(ll i=1;i<=n;i++){//第一次处理 
			if(sss1[i].s>=0){
				if(sss1[i].biao==2){
					if(n2<n/2){
						n2++;
						ans+=sss1[i].s;
						n1--;
					}
					else{
						if(sss1[i].ss>0&&n3<n/2){
							n3++;
							n1--;
							ans+=sss1[i].ss;
						}
					}
				}	
				else if(sss1[i].biao==3){
					if(n3<n/2){
						n3++;
						ans+=sss1[i].s;
						n1--;
					}
					else{
						if(sss1[i].ss>0&&n2<n/2){
							n2++;
							n1--;
							ans+=sss1[i].ss;
						}
					}
				}
			}
			else{//如果n1还是不符合条件 
				if(n1>n/2){
					if(sss1[i].biao==2){
						if(n2<n/2){
							ans+=sss1[i].s;
							n2++;
							n1--;
						}
						else{
							if(n3<n/2){
								ans+=sss1[i].ss;
								n3++;
								n1--;
							}
						}
					}
					else{
						if(n3<n/2){
							ans+=sss1[i].s;
							n3++;
							n1--;
						}
						else{
							if(n2<n/2){
								ans+=sss1[i].ss;
								n2++;
								n1--;
							}
						}
					}
				}
			}
		}

		cout<<ans<<endl;
	}
	return 0; 
}
