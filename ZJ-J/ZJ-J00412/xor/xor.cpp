#include<iostream>
#include<cstdio>
using namespace std;
int n,a[500002],k,mx;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	int lk=0;
	for(int r=0;r<n;r++){
		int v=0;
		for(int j=r;j>=lk;j--){
			v^=a[j];
			if(v==k){
				mx++;
				lk=r+1;
			}
		}
	}
	cout<<mx;
	return 0;
}
