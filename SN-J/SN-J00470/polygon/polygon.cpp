#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
    long long a[5001];
	cin>>n;
	long long max=0;
	long long y=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long l=1,r=3;
	long long u=0;
	long long o=0;
	for(int i=1;i<=0;i++){
		for(l;l<=r;l++){
			if(max<a[l]){
				max=a[l];
			}
			y+=a[l];
		}
		if(y>max*2){
			o++;
		}else{
			l++;
			r++;
		}

	}
	cout<<o;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
