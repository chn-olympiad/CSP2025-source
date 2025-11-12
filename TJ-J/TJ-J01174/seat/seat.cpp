#include<bits/stdc++.h>
using namespace std;
int n[10];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int n[110],n1[11][11],ans=0,cnt,ji=a*b;
	for(int i=1;i<=a*b;i++){
		cin>>n[i];
	}
	cnt=n[1];
	sort(n+1,n+a*b+1);
	for(int i=1;i<=b;i++){
		for(int j=1;j<=a;j++){
			n1[j][i]=n[ji--];
			if(n1[j][i]==cnt) cout<<i<<' '<<j;
		}
		i++;
		for(int j=a;j>=1;j--){
			n1[j][i]=n[ji--];
			if(n1[j][i]==cnt) cout<<i<<' '<<j;
		}
	}
	return 0;
}
