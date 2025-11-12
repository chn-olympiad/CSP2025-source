#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[999][999],num=0,sum=0,o[999]={0};
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
	}
	for(int k=0;k<t;k++){
		for(int i=0;i<3;i++){
			if(o[0]<=n/2 || o[1]<=n/2 || o[2]<=n/2){
				for(int j=0;j<n;j++){
					o[i]+=1;
					sum+=a[j][i];
				}
			}
			else{
				for(int j=n/2-1;j<n;j++){
					o[i]+=1;
					if(i!=2){
						sum+=a[j][i+1];
					}
					else{
						sum+=a[j][i-1];
					}
				}
			}
			if(num<sum){
				num=sum;
			}
		}
		cout<<num<< endl;
		for(int q=0;q<3;q++){
			o[q]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
