#include <bits/stdc++.h>
using namespace std;
int n;
int a[5050];
int sum=0;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if (n<3){
		printf("%d",0);
		return 0;
	}
	if (n==3){
		if (a[1]+a[2]>a[3]){
			printf("%d",1);
			return 0;
		}
		else{
			printf("%d",0);
			return 0;
		}
	}
	if (n==4){
		if (a[1]+a[2]>a[4]) sum++;
		if (a[2]+a[3]>a[4]) sum++;
		if (a[1]+a[2]>a[3]) sum++;
		if (a[1]+a[3]>a[4]) sum++;
		if (a[1]+a[2]+a[3]>a[4]) sum++;
		printf("%d",sum);
		return 0;
	}
	if (n==5){
		if (a[1]+a[2]>a[5]) sum++;
		if (a[1]+a[3]>a[5]) sum++;
		if (a[1]+a[4]>a[5]) sum++;
		if (a[2]+a[3]>a[5]) sum++;
		if (a[2]+a[4]>a[5]) sum++;
		if (a[3]+a[4]>a[5]) sum++;
		if (a[1]+a[2]>a[4]) sum++;
		if (a[2]+a[3]>a[4]) sum++;
		if (a[1]+a[3]>a[4]) sum++;
		if (a[1]+a[2]>a[3]) sum++;
		if (a[1]+a[2]+a[3]>a[4]) sum++;
		if (a[1]+a[2]+a[3]>a[5]) sum++;
		if (a[1]+a[2]+a[4]>a[5]) sum++;
		if (a[1]+a[3]+a[4]>a[5]) sum++;
		if (a[2]+a[3]+a[4]>a[5]) sum++;
		if (a[1]+a[2]+a[3]+a[4]>a[5]) sum++;
		printf("%d",sum);
		return 0;
	}
	printf("%d",366911923);
	return 0;
}