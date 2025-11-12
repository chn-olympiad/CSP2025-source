#include<bits/stdc++.h>
#define IXcape cout<<endl;return 0
#define Venti cout<<"\nVenti!\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
using namespace std;
const int V=100010;
int t,n,ans;
int sum1,sum2,sum3;
int cnt1,cnt2,cnt3;
int max1,max2,max3;
int a[V][4];
priority_queue<pii>q;

inline
void clearx(void){
	for(int i=1;i<=n;i++)
		a[i][1]=a[i][2]=a[i][3]=0;
	cnt1=cnt2=cnt3=max1=max2=max3=sum1=sum2=sum3=ans=0;
	while(!q.empty()) q.pop();
	return;
}

inline
void tj(int i){
	if(a[i][1]==a[i][2]&&a[i][2]==a[i][3]){
		max1++,max2++,max3++;
	}
	else if(a[i][1]==a[i][2]&&a[i][1]>a[i][3]){
		max1++,max2++;
	}
	else if(a[i][2]==a[i][3]&&a[i][2]>a[i][1]){
		max3++,max2++;
	}
	else if(a[i][1]==a[i][3]&&a[i][1]>a[i][2]){
		max3++,max1++;
	}
	else{
		if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
			max1++;	
		}
		if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
			max2++;
		}
		if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]){
			max3++;
		}
	}
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		clearx();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			sum1+=a[i][1];
			sum2+=a[i][2];
			sum3+=a[i][3];
			tj(i);
		}
		if(max1>=max2&&max1>=max3){
			ans=sum1;
			cnt1=n;
			for(int i=1;i<=n;i++)
				q.push(mp(max(a[i][2],a[i][3])-a[i][1],i));
			while(q.top().fi>0||cnt1>(n/2)){
				ans+=q.top().fi;
				cnt1--;
				q.pop();
			}
			cout<<ans<<'\n';
		}else if(max2>=max1&&max2>=max3){
			ans=sum2;
			cnt2=n;
			for(int i=1;i<=n;i++)
				q.push(mp(max(a[i][1],a[i][3])-a[i][2],i));
			while(q.top().fi>0||cnt2>(n/2)){
				ans+=q.top().fi;
				cnt2--;
				q.pop();
			}
			cout<<ans<<'\n';
		}else{
			ans=sum3;
			cnt3=n;
			for(int i=1;i<=n;i++)
				q.push(mp(max(a[i][1],a[i][2])-a[i][3],i));
			while(q.top().fi>0||cnt3>(n/2)){
				ans+=q.top().fi;
				cnt3--;
				q.pop();
			}
			cout<<ans<<'\n';
		}
	}
	IXcape;
}
/*
愿风神护佑我。 
*/

