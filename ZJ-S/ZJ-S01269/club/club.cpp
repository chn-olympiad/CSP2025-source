#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int fir,sec,thr;
};
const int N=1e5+10;
node a[N];
int cnt=0;
int A=1,B=1;
bool cmp(node x,node y){
	return x.fir>y.fir;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int op;
	cin>>op;
	while(op--){
		cnt=0;
		A=1;
		cin>>n;
		if(n==2){
			cin>>a[1].fir>>a[1].sec>>a[1].thr;
			cin>>a[2].fir>>a[2].sec>>a[2].thr;
			int t1,t2,t3,t4,t5,t6;
			t1=a[1].fir+a[2].sec;
			t2=a[1].fir+a[2].thr;
			t3=a[1].sec+a[2].fir;
			t4=a[1].sec+a[2].thr;
			t5=a[1].thr+a[2].sec;
			t6=a[1].thr+a[2].fir;
			cnt=max(t1,max(t2,max(t3,max(t4,max(t5,t6)))));
			cout<<cnt<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
		
			cin>>a[i].fir>>a[i].sec>>a[i].thr;
			if(a[i].thr||a[i].sec) A=0;	
		}
		
		if(A){
			
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				cnt+=a[i].fir;
			}
			cout<<cnt<<"\n";
			continue;
		}
		
	}
		
	
	
	return 0;
} 
