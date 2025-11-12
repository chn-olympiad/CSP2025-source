#include<bits/stdc++.h>
#define ll long long
//#define test
using namespace std;
struct node{
	int a,b,c;
}arr[100005];
int T,n,al,bl,cl;
ll ans,tmp;
bool cmp(node a,node b) {
	int a1=max(a.a,max(a.b,a.c)),a2,a3=min(a.a,min(a.b,a.c)),b1=max(b.a,max(b.b,b.c)),b2,b3=min(b.a,min(b.b,b.c));
	if(a.a>=a.b){
		if(a.a<=a.c)a2=a.a;
		else if(a.b>=a.c)a2=a.b;
		else a2=a.c;
	}else{
		if(a.b<=a.c)a2=a.b;
		else if(a.a>=a.c)a2=a.a;
		else a2=a.c;
	}
	if(b.a>=b.b) {
		if(b.a<=b.c)b2=b.a;
		else if(b.b>=b.c)b2=b.b;
		else b2=b.c;
	}else{
		if(b.b<=b.c)b2=b.b;
		else if(b.a>=b.c)b2=b.a;
		else b2=b.c;
	}
	
	if(a1-a2==b1-b2){
		//cout<<"Is This Fucking SAME?"<<a1<<' '<<a2<<' '<<b1<<' '<<b2<<'\n';
		if(a2==b2)return a3<b3;
		return a2<b2;
	}return a1-a2>b1-b2;
	
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		al=bl=cl=tmp=ans=0;
		cin>>n;
		for(int i=1; i<=n; i++)cin>>arr[i].a>>arr[i].b>>arr[i].c;
		int f=0;
		sort(arr+1,arr+1+n,cmp);
		#ifdef test
		cout<<'\n';
		#endif
		for(int i=1; i<=n; i++){
			#ifdef test
			cout<<arr[i].a<<' '<<arr[i].b<<' '<<arr[i].c<<' ';
			#endif
			if(al==n/2) {
				if(arr[i].b>arr[i].c) {
					#ifdef test
					cout<<'B';
					#endif
					ans+=arr[i].b;
				}else{
					#ifdef test
					cout<<'C';
					#endif
					ans+=arr[i].c;
				}
			}else if(bl==n/2) {
				if(arr[i].a>arr[i].c) {
					#ifdef test
					cout<<'A';
					#endif
					ans+=arr[i].a;
				}else{
					#ifdef test
					cout<<'C';
					#endif
					ans+=arr[i].c;
				}
			}else if(cl==n/2) {
				if(arr[i].a>arr[i].b){
					#ifdef test
					cout<<'A';
					#endif
					ans+=arr[i].a;
				}else{
					#ifdef test
					cout<<'B';
					#endif
					ans+=arr[i].b;
				}
			}else{
				if(arr[i].a>arr[i].b){
					if(arr[i].a>arr[i].c){
						#ifdef test
						cout<<'A';
						#endif
						ans+=arr[i].a;
						al++;
					}else{
						#ifdef test
						cout<<'C';
						#endif
						ans+=arr[i].c;
						cl++;
					}
				}else{
					if(arr[i].b>arr[i].c){
						#ifdef test
						cout<<'B';
						#endif
						ans+=arr[i].b;
						bl++;
					}else{
						#ifdef test
						cout<<'C';
						#endif
						ans+=arr[i].c;
						cl++;
					}
				}
			}
			#ifdef test
			cout<<'\n';
			#endif
		}
		cout<<ans<<'\n';
	}
}
/*
	Name: club
	Copyright:SCP Foundation 
	Author: CCFËû¸¡Ä¾ 
	Date: 01/11/25 18:07
	Description: 
*/

