#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*1e5+7;
int n,t,alphaa,bravoo,charliee,alll;
int clbs=3;
int a1[MAXN],a2[MAXN],a3[MAXN];
int ttl[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a1[j];
			cin>>a2[j];
			cin>>a3[j];
			
			if(a1[j]>a2[j]&&a2[j]>a3[j]){//1>2>3and1<=n,go1
				if(alphaa<=n/2){
					alphaa+=1;
					ttl[j]=a1[j];
				}else{	
					bravoo+=1;
					ttl[j]=a2[j];
				}
			}
//132
			if(a1[j]>a3[j]&&a3[j]>a2[j]){//1>3>2and1<=n,go1
				if(alphaa<=n/2){
					alphaa+=1;
					ttl[j]=a1[j];
				}else{	
					charliee+=1;
					ttl[j]=a3[j];
				}
			}
//213
			if(a2[j]>a1[j]&&a1[j]>a3[j]){//2>1>3ad2<=n,go2
				if(bravoo<=n/2){
					bravoo+=1;
					ttl[j]=a2[j];
				}else{
					alphaa+=1;
					ttl[j]=a1[j];
				}
				
			}
//231
			if(a2[j]>a3[j]&&a3[j]>a1[j]){//2>3>1and2<=n,go2
				if(bravoo<=n/2){
					bravoo+=1;
					ttl[j]=a2[j];
				}else{
					charliee+=1;
					ttl[j]=a3[j];
				}
			}
			
//321
			if(a3[j]>a2[j]&&a2[j]>a1[j]){//3>2>1and3<=n,go3
				if(charliee<=n/2){
					charliee+=1;
					ttl[j]=a3[j];
				}else{
					bravoo+=1;
					ttl[j]=a2[j];
				}
			}
//312
			if(a3[j]>a1[j]&&a1[j]>a2[j]){//3>1>2an3<=n,go3
				if(charliee<=n/2){
					charliee+=1;
					ttl[j]=a3[j];
				}else{
					alphaa+=1;
					ttl[j]=a1[j];
				}	
			}
//equals happened:(
//2=1>3
			if(a2[j]==a1[j]&&a1[j]>a3[j]){
				if(bravoo<=alphaa){
					bravoo+=1;
					ttl[j]=a2[j];
				}else{
					alphaa+=1;
					ttl[j]=a1[j];
				}
			}
//2>1=3
			if(a2[j]>a1[j]&&a1[j]==a3[j]){
				if(bravoo<=n/2){
					bravoo+=1;
					ttl[j]=a2[j];
				}else if(alphaa<=charliee){
					alphaa+=1;
					ttl[j]=a1[j];
				}else{
					charliee+=1;
					ttl[j]=a3[j];
				}
			}
//2=3>1
			if(a2[j]>a1[j]&&a2[j]==a3[j]){
				if(bravoo<=charliee){
					bravoo+=1;
					ttl[j]=a2[j];
				}else{
					charliee+=1;
					ttl[j]=a3[j];
				}
			}
//1>2=3
			if(a1[j]>a2[j]&&a2[j]==a3[j]){
				if(alphaa<=n/2){
					alphaa+=1;
					ttl[j]=a1[j];
				}else if(bravoo<=charliee){
					bravoo+=1;
					ttl[j]=a2[j];
				}else{
					charliee+=1;
					ttl[j]=a3[j];
				}
			}
//1=3>2
			if(a1[j]==a3[j]&&a1[j]>a2[j]){
				if(charliee<=alphaa){
					charliee+=1;
					ttl[j]=a3[j];
				}else{
					alphaa+=1;
					ttl[j]=a1[j];
				}
			}
//3>2=1
			if(a3[j]>a2[j]&&a2[j]==a1[j]){
				if(charliee<=n/2){
					charliee+=1;
					ttl[j]=a3[j];
				}else if(bravoo<=alphaa){
					bravoo+=1;
					ttl[j]=a2[j];
				}else{
					alphaa+=1;
					ttl[j]=a1[j];
				}
			}
//1=2=3
			if(a1[j]==a2[j]&&a2[j]==a3[j]){
				if(alphaa<bravoo&&bravoo<charliee){//123
					alphaa+=1;
					ttl[j]=a1[j];
				}else if(alphaa<charliee&&bravoo<alphaa){//213
					bravoo+=1;
					ttl[j]=a2[j];
				}else if(charliee<alphaa&&alphaa<bravoo){//312
					charliee+=1;
					ttl[j]=a3[j];
				}else if(alphaa==bravoo&&bravoo<charliee){//1=2<3
					alphaa+=1;
					ttl[j]=a1[j];
				}else if(alphaa==charliee&&charliee<bravoo){//1=3<2
					charliee+=1;
					ttl[j]=a3[j];
				}else if(bravoo==charliee&&charliee<alphaa){//2=3<1
					bravoo+=1;
					ttl[j]=a2[j];
				}else{
					alphaa+=1;
					ttl[j]=a1[j];
				}
			}
		for(int soso=0;soso<MAXN;soso++){
			alll+=ttl[soso];
			ttl[soso]=0;
		}
			
		
		}
		cout<<alll;
		alll=0;
	
	
	
	}
	return 0;
}