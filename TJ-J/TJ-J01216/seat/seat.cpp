#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[50][50],sum[100005],cnt=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int rst;
	cin>>rst;
	for(int i=1;i<=n*m-1;i++){
		cin>>sum[i];
	}
	sort(sum+1,sum+n*m,cmp);
	int flag=0;
	for(int i=1;i<=m;i++){
		if(!flag){
			for(int j=1;j<=n;j++){
		        a[j][i]=sum[cnt];
				cnt++;	
		    }
		    flag=1;
		}
		else{
			for(int j=n;j>=1;j--){
		        a[j][i]=sum[cnt];
				cnt++;	
		    }
		    flag=0;
		}
	}
	flag=0;
	for(int i=1;i<=m;i++){
		if(!flag){
			for(int j=1;j<=n;j++){
		        if(rst>a[j][i]){
		        	cout<<i<<" "<<j<<endl;
					return 0; 
				}    	
		    }
		    flag=1;
		}
		else{
			for(int j=n;j>=1;j--){
		       	if(rst>a[j][i]){
		        	cout<<i<<" "<<j<<endl;
					return 0; 
				} 
		    }
		    flag=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
