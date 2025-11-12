#include<bits/stdc++.h>
using namespace std;
int a[10002],ans=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	sort(a+1,a+n+1,cmp);
	if(n==3&&(a[1]+a[3]+a[2])>2*a[3])ans+=1;
	else if(n==4){
		if((a[1]+a[3]+a[2])>2*a[3])ans++;
		if((a[1]+a[4]+a[2])>2*a[4])ans++;
		if((a[1]+a[3]+a[4])>2*a[4])ans++;
		if((a[4]+a[3]+a[2])>2*a[4])ans++;
		if((a[1]+a[3]+a[2]+a[4])>2*a[4])ans++;
	}
	else if(n==5){
		if((a[1]+a[3]+a[2])>2*a[3])ans++;
		if((a[1]+a[4]+a[2])>2*a[4])ans++;
		if((a[1]+a[5]+a[2])>2*a[5])ans++;
		if((a[1]+a[3]+a[4])>2*a[4])ans++;
		if((a[1]+a[3]+a[5])>2*a[5])ans++;
		if((a[1]+a[4]+a[5])>2*a[5])ans++;
		if((a[1]+a[3]+a[2]+a[4])>2*a[4])ans++;
		if((a[1]+a[3]+a[2]+a[5])>2*a[5])ans++;
		if((a[1]+a[4]+a[2]+a[5])>2*a[5])ans++;
		if((a[1]+a[3]+a[4]+a[5])>2*a[5])ans++;
		if((a[2]+a[3]+a[4]+a[5])>2*a[5])ans++;
		
	}
	cout<<ans;
	return 0;
} 
