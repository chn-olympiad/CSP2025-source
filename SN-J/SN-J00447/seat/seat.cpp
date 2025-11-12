#include<bits/stdc++.h>
#define forf(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int N=105;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,row=0,line=0;
	cin>>n>>m;
	forf(i,1,n*m){
		cin>>a[i];
	}
	int mark=a[1];
	sort(a+1,a+n*m+1,cmp);
//	forf(i,1,n*m) cout<<a[i]<<" ";
//	cout<<endl;
	forf(i,1,n*m){
		if(a[i]==mark){
//			cout<<i<<endl;
			row=i/n;
			if(i%n>0){
				row++;
				if(row & 1){
					line=i%n;
				}else{
					line=n+1-i%n;
				}
			}else{
				if(row & 1) line=n;
				else line=1;
			}
			
		}
	}
	cout<<row<<" "<<line;
	return 0;
}

