#include <bits/stdc++.h>
using namespace std;
int n,m,len,x,bh,cnt,a[105];
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++)
		if(a[i]==x){
			bh=i;
			break;
		}
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				cnt++;
				if(cnt==bh){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(cnt==bh){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
