#include<bits/stdc++.h> 
using namespace std;
long long a[10010],b[10010],c[10010],ans[5],n,t,a1,b1,c1,x,t1,t2,t3;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int min=0,y=0;
	cin>>t;
	while(t>0){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(min<a[i]){
				x=1;
				min=a[i];
			}
			if(min<b[i]){
				x=2;
				min=b[i];
			}
			if(min<c[i]){
				x=3;
				min=c[i];
			}
			if(x==1&&t1<=n/2){
				a1+=min;
				t1++;
			}else if(x==2&&t2<=n/2){
				b1+=min;
				t2++;
			}else if(x==3&&t3<=2){
				c1+=min;
				t3++;
			}
			min=0;		
		}
		y++;
		ans[y]=a1+b1+c1;
		t--;
		a1=0;b1=0;c1=0;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 




