#include<bits/stdc++.h>
/*fjx 20120225 rp++*/
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAX=1e7+5;
const ll N=0;
int a[1000];
struct node{
	int l,h;
}b[1000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int s=n*m;
	int ii=1;
	int iii=0;
	for(int i=1;i<=s;i++){
		cin>>a[i];
		if(i%n==0){
			b[i].l=ii++;
		}
		else{
			b[i].l=ii; 
		}
		if((i-1)%n==0){
			if(b[i].l%2==1){
				iii=1;
			}else iii=n;
		}
		if(b[i].l%2==1){
			b[i].h=iii++;
		}else b[i].h=iii--;
	}
	int o=a[1];
	sort(a+1,a+1+s,cmp);
	for(int i=1;i<=s;i++){
		if(a[i]==o){
			cout<<b[i].l<<" "<<b[i].h;
			return 0;
		}
	}
	
	return 0;
} 
/*
3 3
94 95 96 97 98 99 100 93 92
*/
