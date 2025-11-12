#include<bits/stdc++.h>
using namespace std;
vector<int>a,b,c;//记录每个学生踢出部门最小的代价 
long long ans=0;
int n;
void work(){
	ans=0;
	a.clear(),b.clear(),c.clear();
	cin>>n;
	for(int i=1;i<=n;i++){
		int tool1,tool2,tool3;
		cin>>tool1>>tool2>>tool3;
		if(tool1>=tool2&&tool1>=tool3)
			a.push_back(tool1-max(tool2,tool3)),ans+=tool1;
		else if(tool2>=tool1&&tool2>=tool3)
			b.push_back(tool2-max(tool1,tool3)),ans+=tool2;
		else
			c.push_back(tool3-max(tool1,tool2)),ans+=tool3;
	}
	if(a.size()>n/2){
		int dif=a.size()-n/2;
		sort(a.begin(),a.end());
		for(int i=0;i<dif;i++)
			ans-=a[i];
	}
	else if(b.size()>n/2){
		int dif=b.size()-n/2;
		sort(b.begin(),b.end());
		for(int i=0;i<dif;i++)
			ans-=b[i];
	}
	else if(c.size()>n/2){
		int dif=c.size()-n/2;
		sort(c.begin(),c.end());
		for(int i=0;i<dif;i++)
			ans-=c[i];
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
		work();
	return 0;
}
