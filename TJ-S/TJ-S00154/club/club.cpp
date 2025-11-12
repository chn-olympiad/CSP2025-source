#include<bits/stdc++.h>
#define int long long
#define cen cout << "\n"
using namespace std;
struct node{
	int val,id;
};
node ar[100009][5];
int sum[5];
bool cmp(node a,node b){
	return a.val<b.val;
}
void f(){
	for(int i=0;i<=1e5+8;i++){
		for(int j=0;j<=4;j++){
			ar[i][j].val=ar[i][j].id=0;
		}
	}
	for(int i=0;i<=4;i++){
		sum[i]=0;
	}
	int n;
	cin >> n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin >> ar[i][1].val >> ar[i][2].val >> ar[i][3].val;
		ar[i][1].id=1;ar[i][2].id=2;ar[i][3].id=3;
		sort(ar[i]+1,ar[i]+1+3,cmp);
		sum[ar[i][3].id]++;
		ans+=ar[i][3].val;
	}
	int cnt=0;
	vector<int> temp;
	for(int i=1;i<=3;i++){
		if(sum[i]>n/2){
			cnt=sum[i]-n/2;
			for(int j=1;j<=n;j++){
				if(ar[j][3].id==i){
					temp.push_back(ar[j][3].val-ar[j][2].val);
				}
			}
		}
	}
	if(cnt==0){
		cout << ans;
		return;
	}
	sort(temp.begin(),temp.end());
	for(int i=0;i<cnt;i++){
		ans-=temp[i];
	}	
	cout << ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		f();
		cen;
	}
	return 0;
}
