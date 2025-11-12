#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,a[100005],a1,cnt=0,r;
	int h,l;
	cin>>n>>m;
	a1=n*m;
	for(int i=0;i<=a1;i++) cin>>a[i];
		r=a1;
		for(int i=;i<=a1;i++) if(a[i]>r) cnt++;
	if(cnt<n){
		l=1;
	} else if(cnt>n){
		if(cnt%n!=0) l=cnt/n+1;
		else l=cnt/n;
	}
	if(l%2!=0) h=cnt%n;
	else h=n-(cnt%n-1);
	if(h=0) h=1; 
	cout<<l<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
