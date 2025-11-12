#include<bits/stdc++.h>
using namespace std;
int arr[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt;
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
	}
	int R=arr[1];
	sort(arr+1,arr+1+n*m,cmp);
	int hang=0;
	int lie=1;
	int tmp=1;
	int a=0;
	int i=0;
	bool flag=false;
	if(n==1){
		for(int j=1;j<=n*m;j++){
			if(arr[j]==R){
				cout<<j<<" "<<1;
			}
		}
		return 0;
	}
	while(cnt>0){
		hang+=tmp;
		a++;
		cout<<hang<<lie<<endl;
		if(arr[a]==R){
			cout<<lie<<" "<<hang;
			break;
		}
		i++;
		if(i==n){
			i=0;
			lie++;
		}
		if(flag){
			flag=false;
			if(hang==n){
				tmp=-1;
			}
			else{
				tmp=1;
			}
			continue;
		}
		if((hang==n || hang==1) && a!=1){
			flag=true;
			tmp=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
