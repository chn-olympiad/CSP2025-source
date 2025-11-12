#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	int w=a[1];
	sort(a+1,a+n*m+1,cmp);
	int q[110][110],s=1,l=1;
	for(int i=1;i<=m;i++){
		if(l%2!=0){
			for(int j=1;j<=n;j++){
				q[j][i]=a[s];
				s++;
			}
			l++;
		}
		else{
			for(int j=n;j>=1;j--){
				q[j][i]=a[s];
				s++;
			}
			l++;	
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(q[j][i]==w){
			cout<<i<<" "<<j;
			break;
			}
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
	
}
