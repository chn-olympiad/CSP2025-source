#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,t,gh[100010];
int as[20]={};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;//n hang m lie
	t=n*m;
	for(int i =1;i<=t;i++){
		cin>>gh[i];
	}
	int r = gh[1];
	sort(gh+1,gh+t+1,cmp);
	for(int i =1;i<=t;i++){
		if(gh[i]==r){
			int y=i%n;
			int x=i/n;
			if(!y)y=n;
			else x++;
			if(x%2==0)y=n-y+1;
			cout << x<<" "<<y;
			break;
		}
	}
	return 0;
}
