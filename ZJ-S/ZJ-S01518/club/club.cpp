#include<bits/stdc++.h>
using namespace std;
struct satisfy{
	int s1;
	int s2;
	int s3;
}a[100011];
int t,n,ans;
vector<int> b1,b2,b3;
bool cmp1(int x1,int x2){
	return max(a[x1].s2,a[x1].s3)-a[x1].s1>max(a[x2].s2,a[x2].s3)-a[x2].s1;
}
bool cmp2(int x1,int x2){
	return max(a[x1].s1,a[x1].s3)-a[x1].s2>max(a[x2].s1,a[x2].s3)-a[x2].s2;
}
bool cmp3(int x1,int x2){
	return max(a[x1].s1,a[x1].s2)-a[x1].s3>max(a[x2].s1,a[x2].s2)-a[x2].s3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		b1.clear();
		b2.clear();
		b3.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			if(a[i].s1>=a[i].s2&&a[i].s1>=a[i].s3){
				ans+=a[i].s1;
				b1.emplace_back(i);
			}
			else if(a[i].s2>=a[i].s1&&a[i].s2>=a[i].s3){
				ans+=a[i].s2;
				b2.emplace_back(i);
			}
			else{
				ans+=a[i].s3;
				b3.emplace_back(i);
			}
		}
		if(b1.size()>n/2){
			sort(b1.begin(),b1.end(),cmp1);
			for(int i=0;b1.size()-i>n/2;i++){
				ans+=(max(a[b1[i]].s2,a[b1[i]].s3)-a[b1[i]].s1);
			}
		}
		else if(b2.size()>n/2){
			sort(b2.begin(),b2.end(),cmp2);
			for(int i=0;b2.size()-i>n/2;i++){
				ans+=(max(a[b2[i]].s1,a[b2[i]].s3)-a[b2[i]].s2);
			}
		}
		else if(b3.size()>n/2){
			sort(b3.begin(),b3.end(),cmp3);
			for(int i=0;b3.size()-i>n/2;i++){
				ans+=(max(a[b3[i]].s1,a[b3[i]].s2)-a[b3[i]].s3);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}