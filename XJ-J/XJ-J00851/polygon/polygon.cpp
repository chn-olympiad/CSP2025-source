#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+5];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(n<3){
			cout<<"0";
			return 0;
		}
		else if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<"1";
			return 0;
		}else {
			cout<<"0";
			return 0;
		}
	}
	if(n>3){
		for(int i=3;i<=n;i++){
			if(i==3){
				for(int j=1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int h=k+1;h<=n;h++){
							if(a[j]+a[k]+a[h]>a[h]*2){
								ans++;
							}
						}
					}
				}
			}
			if(i==4){
				for(int j=1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int h=k+1;h<=n;h++){
							for(int g=h+1;g<=n;g++)
							if(a[j]+a[k]+a[h]+a[g]>a[g]*2){
								ans++;
							}
						}
					}
				}
			}
			if(i==5){
				for(int j=1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int h=k+1;h<=n;h++){
							for(int g=h+1;g<=n;g++)
							for(int d=g+1;d<=n;d++)
							if(a[j]+a[k]+a[h]+a[g]+a[d]>a[d]*2){
								ans++;
							}
						}
					}
				}
			}
			if(i==6){
				for(int j=1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int h=k+1;h<=n;h++){
							for(int g=h+1;g<=n;g++)
							for(int d=g+1;d<=n;d++)
							for(int s=d+1;s<=n;s++)
							if(a[j]+a[k]+a[h]+a[g]+a[d]+a[s]>a[s]*2){
								ans++;
							}
						}
					}
				}
			}
			if(i==7){
				for(int j=1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int h=k+1;h<=n;h++){
							for(int g=h+1;g<=n;g++)
							for(int d=g+1;d<=n;d++)
							for(int s=d+1;s<=n;s++)
							for(int q=s+1;q<=n;q++)
							if(a[j]+a[k]+a[h]+a[g]+a[d]+a[s]+a[q]>a[q]*2){
								ans++;
							}
						}
					}
				}
			}
			if(i==8){
				for(int j=1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int h=k+1;h<=n;h++){
							for(int g=h+1;g<=n;g++)
							for(int d=g+1;d<=n;d++)
							for(int s=d+1;s<=n;s++)
							for(int q=s+1;q<=n;q++)
							for(int w=q+1;w<=n;w++)
							if(a[j]+a[k]+a[h]+a[g]+a[d]+a[s]+a[q]>a[q]*2){
								ans++;
							}
						}
					}
				}
			}
			if(i==9){
				for(int j=1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int h=k+1;h<=n;h++){
							for(int g=h+1;g<=n;g++)
							for(int d=g+1;d<=n;d++)
							for(int s=d+1;s<=n;s++)
							for(int q=s+1;q<=n;q++)
							for(int w=q+1;w<=n;w++)
							for(int e=w+1;e<=n;e++)
							if(a[j]+a[k]+a[h]+a[g]+a[d]+a[s]+a[q]>a[q]*2){
								ans++;
							}
						}
					}
				}
			}
			if(i==10){
				for(int j=1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int h=k+1;h<=n;h++){
							for(int g=h+1;g<=n;g++)
							for(int d=g+1;d<=n;d++)
							for(int s=d+1;s<=n;s++)
							for(int q=s+1;q<=n;q++)
							for(int w=q+1;w<=n;w++)
							for(int e=w+1;e<=n;e++)
							for(int r=e+1;r<=n;r++)
							if(a[j]+a[k]+a[h]+a[g]+a[d]+a[s]+a[q]>a[q]*2){
								ans++;
							}
						}
					}
				}
			}
		}
	}
    cout<<ans;
	return 0;
}
