#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int aaa,int bbb){
	return aaa>bbb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1,f=0;
	bool c=0;
	for(int xb=1;xb<=n*m;xb++){
		if(a[xb]==r){
			cout<<j<<' '<<i;
			break;
		}	
		if(!c&&i!=n) i++;
		else if(!c&&i==n) j++,c=1;
		else if(c&&i!=1) i--;
		else if(c&&i==1) j++,c=0;
	}
	
	return 0;
} 
