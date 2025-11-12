#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n][3];
		int c1=0,c2=0,c3=0,ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int num=max(max(a[i][0],a[i][1]),a[i][2]);
			if(num==a[i][0])c1++;
			if(num==a[i][1])c2++;
			if(num==a[i][2])c3++;
			ans+=num;
		}
		if(c1<=n/2&&c2<=n/2&&c3<=n/2){cout<<ans<<'\n';continue;}
		int ans1=0,ans2=0,ans3=0;
		if(c1==max(max(c1,c2),c3)){//1组人较多时
			pair<int,int> num[n];
			int j=0;
			//统计最大值为1组的人数
			for(int i=0;i<n;i++)
				if(a[i][0]==max(max(a[i][0],a[i][1]),a[i][2]))
					num[j].first=a[i][0],num[j++].second=i;
			sort(num,num+j);
			bool b[n]={};
			//从大到小选1组值最大的人
			for(int i=j-1;i>=j-n/2;i--)
				ans1+=num[i].first,b[num[i].second]=1;
			//剩下的人从2组和3组里选最大值
			for(int i=0;i<n;i++)
				if(!b[i])ans1+=max(a[i][1],a[i][2]);
		}
		if(c2==max(max(c1,c2),c3)){//2组人较多时
			pair<int,int> num[n];
			int j=0;
			//统计最大值为2组的人数
			for(int i=0;i<n;i++)
				if(a[i][1]==max(max(a[i][0],a[i][1]),a[i][2]))
					num[j].first=a[i][1],num[j++].second=i;
			sort(num,num+j);
			bool b[n]={};
			//从大到小选2组值最大的人
			for(int i=j-1;i>=j-n/2;i--)
				ans2+=num[i].first,b[num[i].second]=1;
			//剩下的人从1组和3组里选最大值
			for(int i=0;i<n;i++)
				if(!b[i])ans2+=max(a[i][0],a[i][2]);
		}
		if(c3==max(max(c1,c2),c3)){//3组人较多时
			pair<int,int> num[n];
			int j=0;
			//统计最大值为3组的人数
			for(int i=0;i<n;i++)
				if(a[i][2]==max(max(a[i][0],a[i][1]),a[i][2]))
					num[j].first=a[i][2],num[j++].second=i;
			sort(num,num+j);
			bool b[n]={};
			//从大到小选3组值最大的人
			for(int i=j-1;i>=j-n/2;i--)
				ans3+=num[i].first,b[num[i].second]=1;
			//剩下的人从2组和1组里选最大值
			for(int i=0;i<n;i++)
				if(!b[i])ans3+=max(a[i][0],a[i][1]);
		}
		cout<<max(max(ans1,ans2),ans3)<<'\n';
	}
	return 0;
}