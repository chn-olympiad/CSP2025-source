#include<bits/stdc++.h>
using namespace std;
#define maxn 114
int n,m;
int a[maxn];
int N;
int c,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	N=n*m;
	int target;
	for(int i=1;i<=N;i++){
		cin>>a[i];
		if(i==1)target=a[i];
	}
	sort(a+1,a+1+N,cmp);
	for(int i=1;i<=N;i++){
		if(a[i]==target){
			c=i/n+(i%n?1:0);
			if(c%2){
				r=(i-1)%n+1;
			}else{
				r=n-((i-1)%n);
			}
			break;
		}
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}