#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5e5+10;
int a[N];
int k;
int ans;
struct node{
	int i;
	int num;
	bool operator>(const node a)const{	
		if(num==a.num){
			return i>a.i;
		}
		return num>a.num;
	}
	bool operator<(const node a)const{
		if(num==a.num){
			return i<a.i;
		}
		return num<a.num;
	}
};
vector<node> end1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				end1.push_back({i,j});
				break;
			}
		}
	}
//	int sum=0;
//	int l=1,r=1;
//	while(l<=r){
//		if(l>1){
//			sum^=a[l-1];
//		}
//		for(;r<=n;r++){
//			sum^=a[r];
//			if(sum==k){
//				end1.push_back({l,r});
//			}
//		}
//		l++;
//		r++;
//	}
	int last;
	sort(end1.begin(),end1.end());
	for(int i=0;i<end1.size();i++){
		if(i==0){
			ans++;
			last=end1[i].num;
		}
		else{
			if(end1[i].i>last){
				ans++;
				last=end1[i].num;
			}
		}
	}
	cout<<ans;
	return 0;
}
