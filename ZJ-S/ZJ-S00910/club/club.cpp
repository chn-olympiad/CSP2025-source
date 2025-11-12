#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define dFor(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
#define MAXN 100005
int n;
struct Node{
	long long x[3];
	int pos;
}a[MAXN];
int t[3];
bool cmp1(int a,int b){
	return a>b;
}
bool cmp2(Node a,Node b){
	return (a.x[0]-a.x[1])<(b.x[0]-b.x[1]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		long long ans=0;
		For(i,0,2){
			t[i]=0;
		}
		For(i,1,n){
			long long Max=-1;
			For(j,0,2){
				cin>>a[i].x[j];
				if(a[i].x[j]>Max){
					Max=a[i].x[j];
					a[i].pos=j;
				}
			}
			ans+=Max;
			t[a[i].pos]++;
			sort(a[i].x,a[i].x+3,cmp1);
		}
		int p=-1;
		For(i,0,2){
			if(t[i]>n/2){
				p=i;
			}
		}
		if(p==-1){
			cout<<ans<<endl;
			continue;
		}
		sort(a+1,a+n+1,cmp2);
		For(i,1,n){
			if(a[i].pos==p){
				ans-=(a[i].x[0]-a[i].x[1]);
				t[p]--;
				if(t[p]<=n/2){
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
