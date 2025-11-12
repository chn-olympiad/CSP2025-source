#include<bits/stdc++.h>
using namespace std;
int a[105];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	int cnt=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i<=n*m;i++){
		if(a[i]==t){
			cnt++;
			break;
		}
		else cnt++;
	}
	int h,l;
	if(cnt>m){
		if(cnt%n!=0){
			l=cnt/n+1;
		}
		else{
			l = cnt/n;
		}
		if(l%2==0&&cnt%n!=0){
			if(n+1-cnt%(n*m)==0){
				h=n;
			}
			else{
				h = n+1-cnt%(n*m);
			}
		}
		else if(l%2==0&&cnt%n==0){
			h=1;
		}
		else h = cnt%n;
	}
	else{
		l=1;
		h=cnt;
	}
	cout<<l<<" "<<h;
	return 0;
}

