#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int l[110];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s = n*m;
	for(int i=1;i<=s;i++) cin>>l[i];
	int a = l[1];
	for(int i=1;i<=s;i++){
		for(int j=1;j<s;j++){
			if(l[j]<l[j+1]){
				swap(l[j],l[j+1]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(l[n*i-n+j]==a){
					cout<<i<<" "<<j;
					break;
				}
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				if(l[n*i-j+1]==a){
					cout<<i<<" "<<j;
					break;
				}
			}
		}
	}
	return 0;
}
