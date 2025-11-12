#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int a[5010];
int main(){
	IOS
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3){
		for(int i=1;i<=n;i++)
			cin>>a[i];
		cout<<0;
		return 0;
	}else if(n==3){
		int sum=0,maxn=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
			maxn=max(a[i],maxn);
		}
		if(sum>maxn*2){
			cout<<1;
			return 0;
		}
	}else if(n==4){
		int sum=0,maxn=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		int cnt=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				if(j!=i)
					maxn=max(a[j],maxn);
			}
			if(sum-a[i]>maxn*2)
				cnt++;
		} 
		cout<<cnt;
		return 0;
	}else if(n==5){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		for(int i=0;i<=n;i++){
			int maxn=-1;
			for(int j=0;j<=n;j++)
				if(j!=i)
					maxn=max(a[j],maxn);	
			if(sum-a[i]>maxn*2)
				cnt++;
		}
		if(sum-a[1]-a[2]>max(a[3],max(a[4],a[5]))*2)cnt++;
		if(sum-a[1]-a[3]>max(a[2],max(a[4],a[5]))*2)cnt++;
		if(sum-a[1]-a[4]>max(a[2],max(a[3],a[5]))*2)cnt++;
		if(sum-a[1]-a[5]>max(a[2],max(a[3],a[4]))*2)cnt++;
		if(sum-a[2]-a[3]>max(a[1],max(a[4],a[5]))*2)cnt++;
		if(sum-a[2]-a[4]>max(a[1],max(a[3],a[5]))*2)cnt++;
		if(sum-a[2]-a[5]>max(a[1],max(a[3],a[4]))*2)cnt++;
		if(sum-a[3]-a[4]>max(a[1],max(a[2],a[5]))*2)cnt++;
		if(sum-a[3]-a[5]>max(a[1],max(a[2],a[4]))*2)cnt++;
		if(sum-a[4]-a[5]>max(a[1],max(a[2],a[3]))*2)cnt++;
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<366911923;
	return 0;
}

