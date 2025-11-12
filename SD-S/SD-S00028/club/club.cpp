#include <bits/stdc++.h>
#include <iostream>
#define int long long
using namespace std;
int t,n;
struct node{
	int x,y,z; 
}a[100001];
bool cmp1(node a,node b){
	return a.x>b.x;
}
bool cmp2(node a,node b){
	return a.y>b.y;
}
bool cmp3(node a,node b){
	return a.z>b.z;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	cin.tie(0);
//	cout.tie(0);
	cin >> t;
	while(t--){
		int cnt1=0,cnt2=0,cnt3=0,ans=0,ans1=0,ans2=0,ans3=0;
		cin >> n;
		for(int i=1;i<=n;i++)cin >> a[i].x >> a[i].y >> a[i].z;
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			int maxn=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].x==maxn){
				if(cnt1<n/2)cnt1++,ans1+=a[i].x;
				else{
					if(a[i].y>=a[i].z){
						if(cnt2<n/2)cnt2++,ans1+=a[i].y;
						else cnt3++,ans1+=a[i].z;
					}
				}
			}else if(a[i].y==maxn){
				if(cnt2<n/2)cnt2++,ans1+=a[i].y;
				else{
					if(a[i].x>=a[i].z){
						if(cnt1<n/2)cnt1++,ans1+=a[i].x;
						else cnt3++,ans1+=a[i].z;
					}
				}
			}else if(a[i].z==maxn){
				if(cnt3<n/2)cnt3++,ans1+=a[i].z;
				else{
					if(a[i].x>=a[i].y){
						if(cnt1<n/2)cnt1++,ans1+=a[i].x;
						else cnt2++,ans1+=a[i].y;
					}
				}
			}
		}
		cnt1=0,cnt2=0,cnt3=0;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			int maxn=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].y==maxn){
				if(cnt2<n/2)cnt2++,ans2+=a[i].y;
				else{
					if(a[i].x>=a[i].z){
						if(cnt1<n/2)cnt1++,ans2+=a[i].x;
						else cnt3++,ans2+=a[i].z;
					}
				}
			}else if(a[i].x==maxn){
				if(cnt1<n/2)cnt1++,ans2+=a[i].x;
				else{
					if(a[i].y>=a[i].z){
						if(cnt2<n/2)cnt2++,ans2+=a[i].y;
						else cnt3++,ans2+=a[i].z;
					}
				}
			}else if(a[i].z==maxn){
				if(cnt3<n/2)cnt3++,ans2+=a[i].z;
				else{
					if(a[i].x>=a[i].y){
						if(cnt1<n/2)cnt1++,ans2+=a[i].x;
						else cnt2++,ans2+=a[i].y;
					}
				}
			}
		}
		cnt1=0,cnt2=0,cnt3=0;
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++){
			int maxn=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].z==maxn){
				if(cnt3<n/2)cnt3++,ans3+=a[i].z;
				else{
					if(a[i].x>=a[i].y){
						if(cnt1<n/2)cnt1++,ans3+=a[i].x;
						else cnt2++,ans3+=a[i].y;
					}
				}
			}else if(a[i].x==maxn){
				if(cnt1<n/2)cnt1++,ans3+=a[i].x;
				else{
					if(a[i].y>=a[i].z){
						if(cnt2<n/2)cnt2++,ans3+=a[i].y;
						else cnt3++,ans3+=a[i].z;
					}
				}
			}else if(a[i].y==maxn){
				if(cnt2<n/2)cnt2++,ans3+=a[i].y;
				else{
					if(a[i].x>=a[i].z){
						if(cnt1<n/2)cnt1++,ans3+=a[i].x;
						else cnt3++,ans3+=a[i].z;
					}
				}
			}
		}
		ans=max(ans1,max(ans2,ans3));
		ans1=0,ans2=0,ans3=0;
		cnt1=0,cnt2=0,cnt3=0;
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			int maxn=a[i].x;
			if(a[i].x==maxn){
				if(cnt1<n/2)cnt1++,ans1+=a[i].x;
				else{
					if(a[i].y>=a[i].z){
						if(cnt2<n/2)cnt2++,ans1+=a[i].y;
						else cnt3++,ans1+=a[i].z;
					}
				}
			}else if(a[i].y==maxn){
				if(cnt2<n/2)cnt2++,ans1+=a[i].y;
				else{
					if(a[i].x>=a[i].z){
						if(cnt1<n/2)cnt1++,ans1+=a[i].x;
						else cnt3++,ans1+=a[i].z;
					}
				}
			}else if(a[i].z==maxn){
				if(cnt3<n/2)cnt3++,ans1+=a[i].z;
				else{
					if(a[i].x>=a[i].y){
						if(cnt1<n/2)cnt1++,ans1+=a[i].x;
						else cnt2++,ans1+=a[i].y;
					}
				}
			}
		}
		cnt1=0,cnt2=0,cnt3=0;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			int maxn=a[i].y;
			if(a[i].y==maxn){
				if(cnt2<n/2)cnt2++,ans2+=a[i].y;
				else{
					if(a[i].x>=a[i].z){
						if(cnt1<n/2)cnt1++,ans2+=a[i].x;
						else cnt3++,ans2+=a[i].z;
					}
				}
			}else if(a[i].x==maxn){
				if(cnt1<n/2)cnt1++,ans2+=a[i].x;
				else{
					if(a[i].y>=a[i].z){
						if(cnt2<n/2)cnt2++,ans2+=a[i].y;
						else cnt3++,ans2+=a[i].z;
					}
				}
			}else if(a[i].z==maxn){
				if(cnt3<n/2)cnt3++,ans2+=a[i].z;
				else{
					if(a[i].x>=a[i].y){
						if(cnt1<n/2)cnt1++,ans2+=a[i].x;
						else cnt2++,ans2+=a[i].y;
					}
				}
			}
		}
		cnt1=0,cnt2=0,cnt3=0;
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++){
			int maxn=a[i].z;
			if(a[i].z==maxn){
				if(cnt3<n/2)cnt3++,ans3+=a[i].z;
				else{
					if(a[i].x>=a[i].y){
						if(cnt1<n/2)cnt1++,ans3+=a[i].x;
						else cnt2++,ans3+=a[i].y;
					}
				}
			}else if(a[i].x==maxn){
				if(cnt1<n/2)cnt1++,ans3+=a[i].x;
				else{
					if(a[i].y>=a[i].z){
						if(cnt2<n/2)cnt2++,ans3+=a[i].y;
						else cnt3++,ans3+=a[i].z;
					}
				}
			}else if(a[i].y==maxn){
				if(cnt2<n/2)cnt2++,ans3+=a[i].y;
				else{
					if(a[i].x>=a[i].z){
						if(cnt1<n/2)cnt1++,ans3+=a[i].x;
						else cnt3++,ans3+=a[i].z;
					}
				}
			}
		}
		ans=max(ans,max(ans1,max(ans2,ans3)));
		ans1=0,ans2=0,ans3=0;
		cnt1=0,cnt2=0,cnt3=0;
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(cnt1<n/2)cnt1++,ans1+=a[i].x;
			else{
				if(a[i].y>=a[i].z){
					if(cnt2<n/2)cnt2++,ans1+=a[i].y;
					else cnt3++,ans1+=a[i].z;
				}
				if(a[i].z>a[i].y){
					if(cnt3<n/2)cnt3++,ans1+=a[i].z;
					else cnt2++,ans1+=a[i].y;
				}
			}
		}
		cnt1=0,cnt2=0,cnt3=0;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(cnt2<n/2)cnt2++,ans2+=a[i].y;
			else{
				if(a[i].x>=a[i].z){
					if(cnt1<n/2)cnt1++,ans2+=a[i].x;
					else cnt3++,ans2+=a[i].z;
				}
				if(a[i].z>a[i].x){
					if(cnt3<n/2)cnt3++,ans2+=a[i].z;
					else cnt1++,ans2+=a[i].x;
				}
			}
		}
		cnt1=0,cnt2=0,cnt3=0;
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if(cnt3<n/2)cnt3++,ans3+=a[i].z;
			else{
				if(a[i].x>=a[i].y){
					if(cnt1<n/2)cnt1++,ans3+=a[i].x;
					else cnt2++,ans3+=a[i].y;
				}
				if(a[i].y>a[i].x){
					if(cnt2<n/2)cnt2++,ans3+=a[i].y;
					else cnt1++,ans3+=a[i].x;
				}
			}
		}
		ans=max(ans,max(ans1,max(ans2,ans3)));
		cout << ans << "\n";
	}
	return 0;
}

