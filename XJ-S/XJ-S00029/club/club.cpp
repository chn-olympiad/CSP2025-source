#include<iostream> 
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;	
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,s=0;
		cin>>n;
		int a[100000];//b[100000],c[100000];
		long long k=0;
		for(int j=1;j<=n;j++){
			cin>>a[k++]>>a[k++]>>a[k++];	
		}
		sort(a+1,a+n*3+1,cmp);
//		sort(b+1,b+4,cmp);
//		sort(c+1,c+4,cmp);
		for(int i=1;i<=n;i++){
			s+=a[i];
		}
		cout<<s;
	}		
//	fclose(stdin);
//	fclose(stdout); 
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
