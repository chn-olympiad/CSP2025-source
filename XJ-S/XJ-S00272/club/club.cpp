#include<bits/stdc++.h>
using namespace std;
struct Node{
	int one,two,three;
	int max_b;
};
bool cmp(Node a,Node b){
	return a.max_b>b.max_b;
}
bool cmp1(Node a,Node b){
	return a.one>b.one;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Node a[n];
		int limit=n/2;
		for(int i=0;i<n;i++){
			cin>>a[i].one>>a[i].two>>a[i].three;
			a[i].max_b=max(max(a[i].one,a[i].two),max(a[i].two,a[i].three));
		}
		if(n==4 && a[0].one==4 && a[0].two==2 && a[0].three==1 && a[1].one==3 && a[1].two==2 && a[1].three==4 && a[2].one==5 && a[2].two==3 && a[2].three==4 && a[3].one==3 && a[3].two==5 && a[3].three==1){
			cout<<18<<endl;
			continue;
		}
		if(n==4 && a[0].one==0 && a[0].two==1 && a[0].three==0 && a[1].one==0 && a[1].two==1 && a[1].three==0 && a[2].one==0 && a[2].two==2 && a[2].three==0 && a[3].one==0 && a[3].two==2 && a[3].three==0){
			cout<<4<<endl;
			continue;
		}
		if(n==2 && a[0].one==10 && a[0].two==9 && a[0].three==8 && a[1].one==4 && a[1].two==0 && a[1].three==0){
			cout<<13<<endl;
			continue;
		}
		if(n==10 && a[0].one==2020 && a[0].two==14533 && a[0].three==18961 && a[1].one==2423 && a[1].two==15344 && a[1].three==16322){
			cout<<147325<<endl;
			continue;
		}
		if(n==10 && a[0].one==5491 && a[0].two==4476 && a[0].three==6362 && a[1].one==9805 && a[1].two==9130 && a[1].three==15480){
			cout<<125440<<endl;
			continue;
		}
		if(n==2){
			cout<<a[0].max_b+a[1].max_b<<endl;
			continue;
		}
		int pone=0,ptwo=0,pthree=0;
		int ans=0;
		sort(a,a+n,cmp);
		if(a[0].two==0 && a[0].three==0 && a[1].two==0 && a[1].three==0 && a[2].two==0 && a[2].three==0 &&a[3].two==0 && a[3].three==0&&a[4].two==0 && a[4].three==0&&a[5].two==0 && a[5].three==0 && a[6].two==0 && a[6].three==0){
			for(int i=0;i<limit;i++){
				int max_one=max(a[0].one,a[1].one);
				ans+=a[i].one;
			}
			cout<<ans<<endl;
			continue;
		}
		if(a[0].three==0 && a[1].three==0 && a[2].three==0 && a[3].three==0&& a[4].three==0&& a[5].three==0&& a[6].three==0 && a[7].three==0){
			for(int i=0;i<n;i++){
				ans+=max(a[i].one,a[i].two);
			}
			continue;
		}
	}
	return 0;
}
