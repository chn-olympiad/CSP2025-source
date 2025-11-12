#include<bits/stdc++.h>
using namespace std;
long long n,m,Max=0;
long long c[3]={0};
long long a[1000000][3]={0};
long long q[1000000]={0};
bool num[3]={1,1,1};
void sat(long long p,int t=0){
	if(p==-1){ 
		if(t>Max){
			Max=t;
		}
		return;
	}
	for(int i=0;i<3-num[2];i++){
		if(c[i]==m){
			continue;
		}
		c[i]++;
		sat(p-1,t+a[p][i]);
		c[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		m=n/2;
		Max=0;
		c[0]=0;
		c[1]=0;
		c[2]=0;
		for(int j=0;j<n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			q[j]=a[j][0];
			if(a[j][1]!=0){
				num[1]=0;
			}
			if(a[j][2]!=0){
				num[2]=0;
			}
		}
		if(num[1]+num[2]==2){
			sort(q,q+n);
			for(int i=n-1;i>=m;i--){
				Max+=q[i];
			}
		}else sat(n-1);
		cout<<Max<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
