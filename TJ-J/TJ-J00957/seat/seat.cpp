#include<bits/stdc++.h>
using namespace std;
void sort_mark(int a[],int x,int c[]){
	for(int j=0;j<x;j++){
		int maxx=-1,max_index=0;
		for(int i=0;i<x;i++){
			if(a[i]>maxx){
				maxx=a[i];
				max_index=i;
			}
		}
		c[j]=maxx;
		a[max_index]=-1;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m],b[n*m];
	int c[m*m];
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	int r_mark=b[0];
	sort_mark(b,n*m,c);
	int t=0,down=1;
	int j=0;
	for(int i=0;i<n;i++){
		for(j;j<n;){
			a[i][j]=c[t];
			if(c[t]==r_mark){
				cout<<i+1<<" "<<j+1;
				return 0;
			}
			if(j==n-1&&down){
				down=0;
				t++;
				j=n-1;
				break;
			}else if(j==0 && !down){
				down=1;
				t++;
				j=0;
				break;
			}
			if(down) j++;
			else if(!down) j--;
			t++;
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
