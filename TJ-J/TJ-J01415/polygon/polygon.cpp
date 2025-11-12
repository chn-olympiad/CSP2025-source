#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],sum[100005],b,c,d,x,y,f,ma;
string s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3) cout<<0;
	else if(n==3){
		for(int i=1;i<=n;i++){
			y+=a[i];
			ma=max(ma,a[i]);
		}
		if(y>ma*2) cout<<1;
		else cout<<0;
	}
	else if(n==4){
		c=a[1]+a[2]+a[3];
		d=max(a[1],max(a[2],a[3]));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[4];
		d=max(a[1],max(a[2],a[4]));
		if(c>d*2) x++;
		c=a[1]+a[4]+a[3];
		d=max(a[1],max(a[4],a[3]));
		if(c>d*2) x++;
		c=a[4]+a[2]+a[3];
		d=max(a[4],max(a[2],a[3]));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[3]+a[4];
		d=max(a[1],max(a[2],max(a[3],a[4])));
		if(c>d*2) x++;
		cout<<x;
	}
	else if(n==5){
		c=a[1]+a[2]+a[3];
		d=max(a[1],max(a[2],a[3]));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[5];
		d=max(a[1],max(a[2],a[5]));
		if(c>d*2) x++;
		c=a[1]+a[4]+a[2];
		d=max(a[1],max(a[4],a[2]));
		if(c>d*2) x++;
		c=a[4]+a[1]+a[3];
		d=max(a[4],max(a[1],a[3]));
		if(c>d*2) x++;
		c=a[1]+a[3]+a[5];
		d=max(a[1],max(a[3],a[5]));
		if(c>d*2) x++;
		c=a[1]+a[4]+a[5];
		d=max(a[1],max(a[4],a[5]));
		if(c>d*2) x++;
		c=a[2]+a[3]+a[4];
		d=max(a[2],max(a[3],a[4]));
		if(c>d*2) x++;
		c=a[2]+a[3]+a[5];
		d=max(a[2],max(a[3],a[5]));
		if(c>d*2) x++;
		c=a[2]+a[4]+a[5];
		d=max(a[2],max(a[4],a[5]));
		if(c>d*2) x++;
		c=a[4]+a[3]+a[5];
		d=max(a[4],max(a[3],a[5]));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[3]+a[4];
		d=max(a[1],max(a[2],max(a[3],a[4])));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[3]+a[5];
		d=max(a[1],max(a[2],max(a[3],a[5])));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[4]+a[5];
		d=max(a[1],max(a[2],max(a[5],a[4])));
		if(c>d*2) x++;
		c=a[1]+a[5]+a[3]+a[4];
		d=max(a[1],max(a[5],max(a[3],a[4])));
		if(c>d*2) x++;
		c=a[5]+a[2]+a[3]+a[4];
		d=max(a[5],max(a[2],max(a[3],a[4])));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[3]+a[4]+a[5];
		d=max(a[1],max(a[2],max(a[3],max(a[4],a[5]))));
		if(c>d*2) x++;
		cout<<x;
	}
	else if(n==6){
		c=a[1]+a[2]+a[3];
		d=max(a[1],max(a[2],a[3]));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[5];
		d=max(a[1],max(a[2],a[5]));
		if(c>d*2) x++;
		c=a[1]+a[4]+a[2];
		d=max(a[1],max(a[4],a[2]));
		if(c>d*2) x++;
		c=a[4]+a[1]+a[3];
		d=max(a[4],max(a[1],a[3]));
		if(c>d*2) x++;
		c=a[1]+a[3]+a[5];
		d=max(a[1],max(a[3],a[5]));
		if(c>d*2) x++;
		c=a[1]+a[4]+a[5];
		d=max(a[1],max(a[4],a[5]));
		if(c>d*2) x++;
		c=a[2]+a[3]+a[4];
		d=max(a[2],max(a[3],a[4]));
		if(c>d*2) x++;
		c=a[2]+a[3]+a[5];
		d=max(a[2],max(a[3],a[5]));
		if(c>d*2) x++;
		c=a[2]+a[4]+a[5];
		d=max(a[2],max(a[4],a[5]));
		if(c>d*2) x++;
		c=a[4]+a[3]+a[5];
		d=max(a[4],max(a[3],a[5]));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[3]+a[4];
		d=max(a[1],max(a[2],max(a[3],a[4])));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[3]+a[5];
		d=max(a[1],max(a[2],max(a[3],a[5])));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[4]+a[5];
		d=max(a[1],max(a[2],max(a[5],a[4])));
		if(c>d*2) x++;
		c=a[1]+a[5]+a[3]+a[4];
		d=max(a[1],max(a[5],max(a[3],a[4])));
		if(c>d*2) x++;
		c=a[5]+a[2]+a[3]+a[4];
		d=max(a[5],max(a[2],max(a[3],a[4])));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[3]+a[4]+a[5];
		d=max(a[1],max(a[2],max(a[3],max(a[4],a[5]))));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[6];
		d=max(a[1],max(a[2],a[6]));
		if(c>d*2) x++;
		c=a[1]+a[6]+a[3];
		d=max(a[1],max(a[6],a[3]));
		if(c>d*2) x++;
		c=a[1]+a[4]+a[6];
		d=max(a[1],max(a[4],a[6]));
		if(c>d*2) x++;
		c=a[1]+a[5]+a[6];
		d=max(a[1],max(a[5],a[6]));
		if(c>d*2) x++;
		c=a[6]+a[2]+a[3];
		d=max(a[6],max(a[2],a[3]));
		if(c>d*2) x++;
		c=a[4]+a[2]+a[6];
		d=max(a[4],max(a[2],a[6]));
		if(c>d*2) x++;
		c=a[5]+a[2]+a[6];
		d=max(a[5],max(a[2],a[6]));
		if(c>d*2) x++;
		c=a[3]+a[4]+a[6];
		d=max(a[3],max(a[4],a[6]));
		if(c>d*2) x++;
		c=a[3]+a[5]+a[6];
		d=max(a[3],max(a[5],a[6]));
		if(c>d*2) x++;
		c=a[4]+a[5]+a[6];
		d=max(a[4],max(a[5],a[6]));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[3]+a[6];
		d=max(a[1],max(a[2],max(a[3],a[6])));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[4]+a[6];
		d=max(a[1],max(a[2],max(a[4],a[6])));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[5]+a[6];
		d=max(a[1],max(a[2],max(a[5],a[6])));
		if(c>d*2) x++;
		c=a[1]+a[4]+a[3]+a[6];
		d=max(a[1],max(a[4],max(a[3],a[6])));
		if(c>d*2) x++;
		c=a[1]+a[5]+a[3]+a[6];
		d=max(a[1],max(a[5],max(a[3],a[6])));
		if(c>d*2) x++;
		c=a[1]+a[5]+a[4]+a[6];
		d=max(a[1],max(a[5],max(a[4],a[6])));
		if(c>d*2) x++;
		c=a[2]+a[4]+a[3]+a[6];
		d=max(a[2],max(a[4],max(a[3],a[6])));
		if(c>d*2) x++;
		c=a[2]+a[5]+a[3]+a[6];
		d=max(a[2],max(a[5],max(a[3],a[6])));
		if(c>d*2) x++;
		c=a[4]+a[5]+a[3]+a[6];
		d=max(a[4],max(a[5],max(a[3],a[6])));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[3]+a[4]+a[6];
		d=max(a[1],max(a[2],max(a[3],max(a[4],a[6]))));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[3]+a[6]+a[5];
		d=max(a[1],max(a[2],max(a[3],max(a[6],a[5]))));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[6]+a[4]+a[5];
		d=max(a[1],max(a[2],max(a[6],max(a[4],a[5]))));
		if(c>d*2) x++;
		c=a[1]+a[6]+a[3]+a[4]+a[5];
		d=max(a[1],max(a[6],max(a[3],max(a[4],a[5]))));
		if(c>d*2) x++;
		c=a[1]+a[2]+a[3]+a[4]+a[5]+a[6];
		d=max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],a[6])))));
		if(c>d*2) x++;
		cout<<x;
		
	}
	else{
		
	sort(a+1,a+1+n);
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=3;
	while(l<=n-2){
		y=0;
		ma=0;
		for(int i=l;i<=r;i++){
			y+=a[i];
			ma=max(ma,a[i]);
		}
		if(y>ma*2){
			x++;
		}
		if(r<n) r++;
		else{
			l++;
			r=l+2;
		}
	}
	cout<<x;
	}
	
	return 0;
} 
