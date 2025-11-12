#include<bits/stdc++.h> 
#include<cstdio> 
using namespace std;
long long t,cy[100005];
struct num{
	long long n,a[100005][3];
}b[5];
bool cmp(long long n1,long long n2){
    return n1>n2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		long long sum=0;
		cin>>b[i].n;
		for(int j=1;j<=b[i].n;j++){
			cin>>b[i].a[j][1]>>b[i].a[j][2]>>b[i].a[j][3];
		}
		for(int j=1;j<=b[i].n;j++){
			if(b[i].a[j][1]>b[i].a[j][2] && b[i].a[j][1]>b[i].a[j][3]){
				cy[j]=b[i].a[j][1];
			}else{
				cy[j]=b[i].a[j][2];
			}
			
		}
		sort(cy+1,cy+b[i].n+1,cmp);
		for(int j=1;j<=b[i].n/2;j++){
			sum+=cy[j];
		}
        cout<<sum;
	}
	return 0;
	//ÎÒÃ»ÕÐÁË ©Ñ©Ò©n©Ñ©Ò 
}
