#include <bits/stdc++.h>
#define int long long
using namespace std;
struct member{
	int a1,a2,a3;
};
vector<member> f1,f2,f3;
int ans[10];
int n;
bool cmp1(member x,member y){
	if(f2.size()<n/2&&f3.size()<n/2)return max(x.a1-x.a2,x.a1-x.a3)<max(y.a1-y.a2,y.a1-y.a3);
	if(f2.size()<n/2)return x.a1-x.a2<y.a1-y.a2;
	return x.a1-x.a3<y.a1-y.a3;
}
bool cmp2(member x,member y){
	if(f1.size()<n/2&&f3.size()<n/2)return max(x.a2-x.a1,x.a2-x.a3)<max(y.a2-y.a1,y.a2-y.a3);
	if(f1.size()<n/2)return x.a2-x.a1<y.a2-y.a1;
	return x.a2-x.a3<y.a2-y.a3;
}
bool cmp3(member x,member y){
	if(f3.size()<n/2&&f2.size()<n/2)return max(x.a3-x.a2,x.a3-x.a1)<max(y.a3-y.a2,y.a3-y.a1);
	if(f2.size()<n/2)return x.a3-x.a2<y.a3-y.a2;
	return x.a3-x.a1<y.a3-y.a1;
}
signed main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		while(f1.size())f1.erase(f1.begin());
		while(f2.size())f2.erase(f2.begin());
		while(f3.size())f3.erase(f3.begin());
		cin>>n;
		for(int j=1;j<=n;j++){
			int s1,s2,s3;
			cin>>s1>>s2>>s3;
			if(s1>=s2&&s1>=s3){
				f1.push_back({s1,s2,s3});
			}else{
				if(s2>=s1&&s2>=s3){
					f2.push_back({s1,s2,s3});
				}else{
					f3.push_back({s1,s2,s3});
				}	
			}	
				
		}
		for(;f1.size()>n/2||f2.size()>n/2||f3.size()>n/2;){
			if(f1.size()>n/2){
				sort(f1.begin(),f1.begin()+f1.size(),cmp1);
				if(f1[0].a2>=f1[0].a3&&f2.size()<n/2){
					f2.push_back(f1[0]);
				}else{
					if(f3.size()<=n/2){
						f3.push_back(f1[0]);
					}else{
						f2.push_back(f1[0]);
					}	
				}
				f1.erase(f1.begin());
			}
			if(f2.size()>n/2){
				sort(f2.begin(),f2.begin()+f2.size(),cmp2);
				if(f2[0].a1>=f2[0].a3&&f1.size()<n/2){
					f1.push_back(f2[0]);
				}else{
					if(f3.size()<=n/2){
						f3.push_back(f1[0]);
					}else{
						f1.push_back(f1[0]);
					}
				}
				f2.erase(f2.begin());
			}
			if(f3.size()>n/2){
				sort(f3.begin(),f3.begin()+f3.size(),cmp3);
				if(f2[0].a2>=f1[0].a3&&f2.size()<n/2){
					f2.push_back(f3[0]);
				}else{
					if(f1.size()<=n/2){
						f1.push_back(f1[0]);
					}else{
						f2.push_back(f1[0]);
					}
				}
				f3.erase(f3.begin());
			}
		}
		for(int j=0;j<f1.size();j++)ans[i]+=f1[j].a1;
		for(int j=0;j<f2.size();j++)ans[i]+=f2[j].a2;
		for(int j=0;j<f3.size();j++)ans[i]+=f3[j].a3;
	}
	for(int i=1;i<=t;i++)cout<<ans[i]<<"\n";
	return 0;
}