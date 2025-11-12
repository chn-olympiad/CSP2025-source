#include<iostream>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
		int n,m,a[101],b=1,x=0,y=0,cnt=0;
		bool flag=0;
		cin>>n>>m;
		for(int i=1;i<=n*m;i++) cin>>a[i];
		for(int i=2;i<=n*m;i++) if(a[i]>a[1]) b++;
		if(b<=n){
			y=b;flag=1;
		}
		if(flag==0){
			int c=b;
			for(int i=1;1;i++){
				c-=n;
				cnt++;
				if(c<n) break;
			}
			cnt++;
			if(flag==0&&cnt%2==1){
				y=b%n;
			} 
			else if(flag==0&&cnt%2==0){
				y=n-(b%n)+1;
			}
		}
		else if(flag==1){
			int c=b;
			for(int i=1;i;i++){
				c-=n;
				cnt++;
				if(c<n) break;
			}
		}
		x=cnt;
		cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);

	return 0;
}

