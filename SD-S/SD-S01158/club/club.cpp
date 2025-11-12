#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
const int N=2e5+10;
int ans[N],cnt;
struct node{
	int a;
	int b;
	int c;
}no[N];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,nn,anss,mm,cmp;
	cin>>t;
	while(t--){
		anss=0;
		cmp=0;
		cin>>nn;
		mm=nn/2;
		for(int i=1;i<=nn;i++){
			cin>>no[i].a >>no[i].b >>no[i].c ;
		}
		int set1=0,set2=0,set3=0;
		cmp=0;
		for(int i=1;i<=nn;i++){
			int maxx=INT_MIN;
			if(set1<mm){
				if(maxx<no[i].a ){
					maxx=no[i].a ;
				}
			}
			if(set2<mm){
				if(maxx<no[i].b ){
					maxx=no[i].b ;
				}
			}
			if(set3<mm){
				if(maxx<no[i].c ){
					maxx=no[i].c ;
				}
			}
			if(maxx==no[i].a ) set1++;
			if(maxx==no[i].b ) set2++;
			if(maxx==no[i].c ) set3++;
			cmp+=maxx;
		}
		anss=max(anss,cmp);
		set1=0,set2=0,set3=0;
		cmp=0;
		for(int i=nn;i>=1;i--){
			int maxx=INT_MIN;
			if(set1<mm){
				if(maxx<no[i].a ){
					maxx=no[i].a ;
				}
			}
			if(set2<mm){
				if(maxx<no[i].b ){
					maxx=no[i].b ;
				}
			}
			if(set3<mm){
				if(maxx<no[i].c ){
					maxx=no[i].c ;
				}
			}
			if(maxx==no[i].a ) set1++;
			if(maxx==no[i].b ) set2++;
			if(maxx==no[i].c ) set3++;
			cmp+=maxx;
		}
		anss=max(anss,cmp);
		set1=0,set2=0,set3=0;
		cmp=0;
		for(int i=1;i<=nn;i++){
			int maxx=INT_MIN;
			if(set1<mm){
				if(maxx<no[i].a ){
					maxx=no[i].a ;
					set1++;
				}
			}
			else{
				if(set2<mm){
					if(maxx<no[i].b ){
						maxx=no[i].b ;
						set2++;
					}
				}
				else{
					if(set3<mm){
						if(maxx<no[i].c ){
							maxx=no[i].c ;
							set3++;
						}
					}
					else{
						break;
					}
				}
			}
			cmp+=maxx;
		}
		anss=max(anss,cmp);
		set1=0,set2=0,set3=0;
		cmp=0;
		for(int i=nn;i>=1;i--){
			int maxx=INT_MIN;
			if(set1<mm){
				if(maxx<no[i].a ){
					maxx=no[i].a ;
					set1++;
				}
			}
			else{
				if(set2<mm){
					if(maxx<no[i].b ){
						maxx=no[i].b ;
						set2++;
					}
				}
				else{
					if(set3<mm){
						if(maxx<no[i].c ){
							maxx=no[i].c ;
							set3++;
						}
					}
					else{
						break;
					}
				}
			}
			cmp+=maxx;
		}
		anss=max(anss,cmp);
		ans[++cnt]=anss;
	}
	for(int i=1;i<=cnt;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}

