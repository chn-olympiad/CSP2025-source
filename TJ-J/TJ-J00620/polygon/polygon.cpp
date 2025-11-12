#include<bits/stdc++.h>
using namespace std;
int a[5050],a1[5050][5050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s1=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		int ma=a[n-1],n1=n-1,n2=2;
		while(true){
			int sum=0;
			for(int j=0;j<=i;j++){
				sum+=a[n1-j];
			}
			if(sum>ma){
				s1++;
				n1--;
			}else{
				ma=a[n-n2++];
			}if(n-n2<i) break;
		}
	}
	cout<<s1%998;
	return 0;
}
