//Code Originally Designed by Zhang Aoyi, SN-J00400, Shaanxi NOI CSP-J/S 2025
//Lang: C++, Examination Time: 08:30~12:00
//School: Xi'an Aerospace City No.1 (Junior) High School
//Examination Place: NPU Chang'an Campus
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
//priority_queue<int>q;
//priority_queue<int,vector<int>,greater<int> >qq;
//seat
int n,m;
int a[105];
int r;
bool cmp(int tempx,int tempy){
	return tempx>tempy;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+(n*m)+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<endl; 
//	}
	int x=1,y=1;
	//n ÐÐ m ÁÐ 
	for(int i=1;i<=n*m;i++){
		//cout<<x<<" "<<y<<" # ";
		if(a[i]==r){
			break;
		}
		if(x%2==1){
			y++;
		}
		else{
			y--;
		}
		if(y==0){
			x++; y=1;
		}
		if(y==n+1){
			x++; y=n;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}

