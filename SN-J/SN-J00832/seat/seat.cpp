#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101],b,s[11][11],c=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	b=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<m;i++){
		if(i%2==1)
			for(int j=n-1;j>=0;j--){
				s[j][i]=a[c];
				c++;
			}
		if(i%2==0)
			for(int j=0;j<n;j++){
				s[j][i]=a[c];
				c++;
			}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]==b)
				cout<<j+1<<" "<<i+1;
	return 0;
}
