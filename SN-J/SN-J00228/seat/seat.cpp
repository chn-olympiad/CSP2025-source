#include <bits/stdc++.h>

using namespace std;

int n,m,a[1010];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int cnt=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			int sum=(i+m-1)/m;
			printf("%d ",sum);
			int num=i%n;
			if(num==0)
				num=n;
			if(sum%2==0)
				printf("%d",n-num+1);
			else
				printf("%d",num);
			return 0;
		}
	}
}
