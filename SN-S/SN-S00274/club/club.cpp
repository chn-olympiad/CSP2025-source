#include <bits/stdc++.h>
using namespace std;
struct node{
	int sub1;
	int sub2;
	int sub3;
};
bool cmp1(node a, node b){
	if(a.sub1 > b.sub1) return true;
	else if(a.sub1 <= b.sub1) return false;
}
bool cmp2(node a, node b){
	if(a.sub2 > b.sub2) return true;
	else if(a.sub2 <= b.sub2) return false;
}
bool cmp3(node a, node b){
	if(a.sub3 > b.sub3) return true;
	else if(a.sub3 <= b.sub3) return false;
}
int T;
int main(){
//	freopen("club.in", "r", stdin);
//	freopen("club.out","w",stdout);
    cin>>T; 
	while(T--){
		vector<node> DP;
		int ans1=0, c1=0, ans2=0, c2=0, ans3=0, c3=0;
		int n; cin>>n;
		bool bA=1, bB = 1;
		for(int i=0; i<n; i++){
			node one;
			cin>>one.sub1>>one.sub2>>one.sub3;
			if(one.sub3) bB = 0;
			if(one.sub2 || one.sub3) bA = 0;
			DP.push_back(one);
		}
		if(n<=30){
			sort(DP.begin(), DP.end(), cmp1);
			for(int i=0; i<n/2; i++) ans1 += DP[i].sub1;
			sort(DP.begin(), DP.end(), cmp2);
			for(int i=0; i<n/2; i++) ans2 += DP[i].sub2;
			sort(DP.begin(), DP.end(), cmp1);
			for(int i=0; i<n/2; i++) ans3 += DP[i].sub3;
			cout<<max(ans1, max(ans2, ans3));
		}
		if(bA){
			int ans=0;
			sort(DP.begin(), DP.end(), cmp1);
			for(int i=0; i<n/2; i++){
				ans += DP[i].sub1;
			}
			cout<<ans<<endl;
			continue;
		}
		if(bB){
			sort(DP.begin(), DP.end(), cmp1);
			for(int i=0; i<n/2; i++) ans1 += DP[i].sub1;
			sort(DP.begin(), DP.end(), cmp2);
			for(int i=0; i<n/2; i++) ans2 += DP[i].sub2;
			sort(DP.begin(), DP.end(), cmp1);
			cout<<max(ans1, ans2);
		}
	}
}
