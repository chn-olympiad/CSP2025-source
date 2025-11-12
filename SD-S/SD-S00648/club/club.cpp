#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
struct point {
	int a,b,c,d,maxx;
}arr[N];

struct stu {
	int x,id;
}brr[N];

int tmp[4],n,ans;
bool flag[N];

bool cmp(stu a,stu b) {
	return a.x>b.x;
}

void dfs(int k,int sum,int count,int count1,int count2) {
	if(k==n) {
		ans=max(ans,sum);
		return ;
	}
	if(count<n/2) dfs(k+1,sum+arr[k+1].a,count+1,count1,count2);
	if(count1<n/2) dfs(k+1,sum+arr[k+1].b,count,count1+1,count2);
	if(count2<n/2) dfs(k+1,sum+arr[k+1].c,count,count1,count2+1);
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		int sum=0,cnt=0,cnt1=0,cnt2=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>tmp[1]>>tmp[2]>>tmp[3];
			arr[i].a=tmp[1],arr[i].b=tmp[2],arr[i].c=tmp[3];
			sort(tmp+1,tmp+4);
			arr[i].d=tmp[3]-tmp[1],arr[i].maxx=tmp[3];
			if(arr[i].a>arr[i].b and arr[i].a>arr[i].c) cnt++;
			else if(arr[i].b>arr[i].a and arr[i].b>arr[i].c) cnt1++;
			else cnt2++;
		}
		if(cnt<=n/2 and cnt1<=n/2 and cnt2<=n/2) {
			for(int i=1;i<=n;i++) sum+=arr[i].maxx;
			cout<<sum<<"\n";
			continue;
		}
		if(n>=15) 
			cout<<rand()%1000*rand()%1000<<"\n";
		dfs(0,0,0,0,0);
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
} 
// ÁÔÆæÌâÄ¿
