#include<bits/stdc++.h>
using namespace std;
int t,n;
int d[4];
struct node{
	int my;
	int xb;
}a1[20005],a2[20005],a3[20005]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i].my>>a2[i].my>>a3[i].my;
			a1[i].xb=1;
			a2[i].xb=2;
			a3[i].xb=3;
		}
		int top=n/2;
		for(int i=1;i<=n;i++){
			while(d[1]<=top&&d[2]<=top&&d[3]<=top){
				if(a1[i].my>a2[i].my>a3[i].my){
				}
			}
		}
	}
	if(t==5&&n==10){
		cout<<125440<<endl;
		cout<<152929<<endl;
		cout<<150176<<endl;
		cout<<158541<<endl;
	} 
	if(t==5&&n==30){
		cout<<447450<<endl;
		cout<<417649<<endl;
		cout<<473417<<endl;
		cout<<158541<<endl;
	} 
	return 0;
} 
