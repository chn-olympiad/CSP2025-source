#include<bits/stdc++.h>
using namespace std;
#define int long long
const int cd=1e5+5;
int t,n;
struct aaa{       
	int a1,a2,a3;
}a[cd];
bool cmp1(aaa a,aaa b){
	return a.a1>b.a1;
}
bool cmp2(aaa a,aaa b){
	return a.a2>b.a2;
}
bool cmp3(aaa a,aaa b){
	return a.a3>b.a3;
}
bool cmp4(aaa a,aaa b){
	return a.a2-a.a1>b.a2-b.a1;
}
bool cmp5(aaa a,aaa b){
	return a.a1-a.a2>b.a1-b.a2;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		for(int i=1;i<=n;i++){
			a[i].a1=a[i].a2=a[i].a3=0;
		}
		cin>>n;
		
		int cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			cnt2+=(a[i].a2==0);
			cnt3+=(a[i].a3==0);
		}
		if(cnt2==n&&cnt3==n){//A
			int cnt=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				cnt+=a[i].a1;
			}
			cout<<cnt<<"\n";
		}
		else if(cnt3==n){//B
//			cout<<"=======\n";
			vector<aaa> v1,v2,v3;
			for(int i=1;i<=n;i++){
				if(a[i].a1> a[i].a2) v1.push_back(a[i]);
				if(a[i].a1< a[i].a2) v2.push_back(a[i]);
				if(a[i].a1==a[i].a2) v3.push_back(a[i]);
			}
			sort(v1.begin(),v1.end(),cmp1);
			sort(v2.begin(),v2.end(),cmp2);
			sort(v3.begin(),v3.end(),cmp1);
			
			int len3=v3.size();
			if(v1.size()>n/2){
				sort(v1.begin(),v1.end(),cmp4);
				for(int i=0;i<n/2-v2.size();i++){
					if(v2[i].a1-v2[i].a2<0 &&v2.size()<=n/2){
						break;
					}
					v2.push_back(v1[i]);
					v1[i].a1=0;
				}
				
				int sum=0;
				for(auto i:v1) sum+=i.a1;
				for(auto i:v2) sum+=i.a2;
				for(auto i:v3) sum+=i.a1;
				
				cout<<sum<<"\n";
			}
			else if(v2.size()>n/2){
				sort(v2.begin(),v2.end(),cmp5);
				for(int i=0;i<n/2-v1.size();i++){
					if(v2[i].a1-v2[i].a2<0 &&v2.size()<=n/2){
						break;
					}
					v1.push_back(v2[i]);
					v2[i].a2=0;
				}
				
				int sum=0;
				for(auto i:v1) sum+=i.a1;
				for(auto i:v2) sum+=i.a2;
//				for(auto i:v3) sum+=i.a1;
				
				cout<<sum<<"\n";
			}
		}
		else if(n==2){
			int max1=max(a[1].a1+a[2].a2,a[1].a1+a[2].a3);
			int max2=max(a[1].a2+a[2].a1,a[1].a2+a[2].a3);
			int max3=max(a[1].a3+a[2].a1,a[1].a3+a[2].a2);
			int maxl=max(max1,max(max2,max3));
			cout<<maxl<<"\n";
		}
		else{
			int maxl=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int k=1;k<=n;k++){
						if(i==j||j==k||i==k) continue;
						int sum=0;
						int t1=a[i].a1+a[j].a2+a[k].a3;
						int t2=a[i].a3+a[j].a1+a[k].a2;
						int t3=a[i].a2+a[j].a3+a[k].a1;
						sum=max(t1,max(t2,t3));
						maxl=max(maxl,sum);
					}
				}
			}
			
			cout<<maxl<<"\n";
		}
		
	}
	return 0;
}
