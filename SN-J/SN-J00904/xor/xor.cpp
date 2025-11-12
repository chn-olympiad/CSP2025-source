//hhz RP++ SCORE++ pts++
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,g;
const int N=5e5+5;
int a[N];
struct node{
	int x,y;
}cnt[N];
bool cmp(node a,node b){
	if(a.x==b.x){
		return a.y<b.y;
	}
	else{
		return a.x<b.x;
	}
}
int sum=1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>g;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int h=a[j];
			for(int k=j+1;k<=i+j;k++){
				h^=a[k];
			}
			if(h==g){
				sum++;
				cnt[sum].x=j;
				cnt[sum].y=j+1;
			}
		}
	}
	sort(cnt+1,cnt+sum+1,cmp);
	bool num=0,ans;
	for(int i=1;i<=sum;i++){
		if(!num){
			num=cnt[i].x;
			ans=i;
		}
		else{
			if(cnt[i+1].x!=num){
				num=0;
				sum++;
				ans=cnt[i+1].x;
			} 
		}
	}
	cout<<ans;
	return 0;
}//AC
