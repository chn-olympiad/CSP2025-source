#include<bits/stdc++.h>
using namespace std;
long long x[50005],y[50005],n,m,c=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long  a[50005],ans1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		ans1=a[i];
		if(ans1==m){
			x[c]=i;
			y[c]=i;
			c++;
		}
		else{
			for(int j=i+1;j<=n;j++){
				ans1=ans1^a[j];
				if(ans1==m){
					x[c]=i;
					y[c]=j;
					c++;
					break;
				}
			} 
		}
	}
	for(int i=1;i<c;i++){
		for(int j=i+1;j<c;j++){
			if(y[j]<y[i]){
				for(int p=1+i;p<c;p++){
					swap(x[p-1],x[p]);
					swap(y[p-1],y[p]);
				}
				i--;
				c--;
			}
		}
	}
	for(int i=1;i<c;i++){
		for(int j=i+1;j<c;j++){
			if(x[j]<=y[i]){
				for(int p=1+j;p<=c;p++){
					swap(x[p-1],x[p]);
					swap(y[p-1],y[p]);
				}
				i--;
				c--;
			}
		}
	}
	cout<<c-1;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
