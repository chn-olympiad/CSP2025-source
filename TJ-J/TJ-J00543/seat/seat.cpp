#include<bits/stdc++.h>
using namespace std;
int s[105],a[15][15],s1[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,n1,m1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	int a1=s[0];
	sort(s,s+n*m);
	for(int i=n*m-1,j=0;i>=0&&j<n*m;i--,j++){
		s1[j]=s[i];
	}
	int n2=2*n;
	for(int i=0;i<n*m;i++){
		if(i%(n2)<n){
			a[i/n][i%n2]=s1[i];
			if(s1[i]==a1){
				n1=i/n;
				m1=i%n2;
			}
		}
		else if(i%n2>=n){
			a[i/n][i%n2-(i-n-i%n)]=s1[i];
			if(s1[i]==a1){
				n1=i/n;
				m1=i%n2-(i-n-i%n);
			}
		}
		
	}
	cout<<n1+1<<" "<<m1+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
