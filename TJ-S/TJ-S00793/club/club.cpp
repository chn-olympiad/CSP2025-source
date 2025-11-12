#include<bits/stdc++.h>
using namespace std;
int n,t;
struct Node{
	int fir,sec,thi;
}a[100010];
bool cmp1(Node a,Node b){
	return a.fir>b.fir;
}
bool cmp2(Node a,Node b){
	return a.sec>b.sec;
}
bool cmp3(Node a,Node b){
	return a.thi>b.thi;
}
int firmax(){
	sort(a,a+n,cmp1);
	long long cnt=0;
	for(int i=0;i<n/2;i++){
		cnt+=a[i].fir;
	}
	int count2=0,count3=0;
	for(int i=n/2;i<n;i++){
		if(a[i].sec>a[i].thi&&count2<=n/2){
			count2++;
			cnt+=a[i].sec;
		}
		else if(a[i].sec<a[i].thi&&count3<=n/2){
			count3++;
			cnt+=a[i].thi;
		}
		else{
			count2++;
			cnt+=a[i].sec;
		}
	}
	return cnt;
}
int secmax(){
	sort(a,a+n,cmp2);
	long long cnt=0;
	for(int i=0;i<n/2;i++){
		cnt+=a[i].sec;
	}
	int count1=0,count3=0;
	for(int i=n/2;i<n;i++){
		if(a[i].fir>a[i].thi&&count1<=n/2){
			count1++;
			cnt+=a[i].fir;
		}
		else if(a[i].fir<a[i].thi&&count3<=n/2){
			count3++;
			cnt+=a[i].thi;
		}
		else{
			count1++;
			cnt+=a[i].fir;
		}
	}
	return cnt;
}
int thimax(){
	sort(a,a+n,cmp3);
	long long cnt=0;
	for(int i=0;i<n/2;i++){
		cnt+=a[i].thi;
	}
	int count1=0,count2=0;
	for(int i=n/2;i<n;i++){
		if(a[i].fir>a[i].sec&&count1<=n/2){
			count1++;
			cnt+=a[i].fir;
		}
		else if(a[i].fir<a[i].sec&&count2<=n/2){
			count2++;
			cnt+=a[i].sec;
		}
		else{
			count1++;
			cnt+=a[i].fir;
		}
	}
	return cnt;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].fir>>a[i].sec>>a[i].thi;
		}
		cout<<max(firmax(),max(secmax(),thimax()))<<'\n';
	}
	return 0;
}

