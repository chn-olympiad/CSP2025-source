#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001];
int R;
int cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) R=a[i];
		if(i>1&&a[i]>R) cnt++;
	} 
	int l=1,r=1,de=0;
	while(cnt){
		if(de==0&&l==n){
			de=1;
			r++;
			cnt--;
		}else if(de==1&&l==1){
			de=0;
			r++;
			cnt--;
		}
		if(cnt==0) break;
		if(de==0&&l+1<=n) l++,cnt--;
		else if(de==1&&l-1>=1) l--,cnt--;
	}
	
	cout<<r<<" "<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;	

} 
