#include<bits/stdc++.h>
using namespace std;
long long n,k,sum,b1;
vector<long long> a(1,0);
struct Node{
	int x,y;
}b[1000010];
int main(){
	cin>>n>>k;
	for(long long i=1,a1;i<=n;i++){
		cin>>a1;
		a.push_back(a1);
	}for(long long i=1;i<n;i++){
		long long x=a[i];
		if(x==k) b1++,b[b1].x=i,b[b1].y=i;
		for(long long j=i+1;j<=n;j++){
			x^=a[j];
			if(x==k) b1++,b[b1].x=i,b[b1].y=j;
		}
	}for(int i=1,xx=0;i<=b1;i++){
		if(b[i].x>xx){
			xx=b[i].y,sum++;
		}
	}cout<<sum;
	return 0;
}
