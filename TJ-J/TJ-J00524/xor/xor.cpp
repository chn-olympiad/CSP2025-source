#include<iostream>
using namespace std;
bool bi(bool* a,bool* b){
	for(int i=0;i<21;i++){
		if(*(a+i)!=(*b+i))return false;
	}
	return true;
}
void zhao(bool* a,bool*b){
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans[10000001][2];
	cin>>n>>k;
	bool a[n][21];
	bool b[21],bk[21];
	int c;
	for(int i=0;i<n;i++){
		cin>>c;
		int x=0;
		while(c>1){
			a[i][x]=c%2;
			c=c/2;
			x++;
		}
		a[i][x]=1;
	}
	int x=0;
	while(k>1){
		bk[x]=c%2;
		c=c/2;
		x++;
	}
	bk[x]=1;
	x=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<21;j++)b[j]=a[i][j];
		if(bi(&b[0],&bk)){
			ans[x][0]=i;
			ans[x][1]=i;
			x++;
		}else{
			for(int j=i+1;j<n;j++){
				for(int q=0;q<=20;q++){	
					if(b[q]!=a[j][q])b[q]=1;
				}
			if(bi(&b[0],&bk)){
				ans[x][0]=i;
				ans[x][1]=i;
				x++;
			}	
			}
		}
	}
	return 0;
}
