#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int n,m[10];
int x[100005],y[100005],z[100005],a1=0,b1=0,c1=0,a2,b2,c2,ans[10],mm;
int main(){

freopen("club.in","r",stdin);
freopen("club.out","w",stdout);

cin>>n;
for(int j=1;j<n;j++){	
cin>>m[j];
mm=m[j]/2;
for(int i=1;i<=m[j];i++){
	cin>>a[i]>>b[i]>>c[i];
	if(a[i]>=b[i]&&a[i]>=c[i]){
		if(a1<mm){				
		x[i]=a[i];
		y[i]=0;
		z[i]=0;
		a1++;
		ans[j]+=a[i];
		if(a2==0){
			a2=i;
		}else if(a2>=a[i]){
			a2=i;
		}else{
			cout<<"";
		}
	}else{
		if((a[a2]-max(b[a2],c[a2]))<=a[i]){
			
		}else{
			x[i]=0;
			if(b[i]>c[i]){
				b[i]=y[i];
				b1++;
				ans[j]-a[i];
				ans[j]+=b[i];
				if(b2==0){
			b2=i;
		}else if(b2>=b[i]){
			b2=i;
		}else{
			cout<<"";
		}
			}else{
				c[i]=z[i];
				c1++;
				ans[j]-a[i];
				ans[j]+=c[i];
				if(c2==0){
			c2=i;
		}else if(c2>=c[i]){
			c2=i;
		}else{
			cout<<"";
		}
			}
		}
		
	}
	
	}else if(b[i]>=a[i]&&b[i]>=c[i]){		
		if(b1<mm){				
		y[i]=b[i];
		x[i]=0;
		z[i]=0;
		b1++;
		ans[j]+=b[i];
		if(b2==0){
			b2=i;
		}else if(b2>=b[i]){
			b2=i;
		}else{
			cout<<"";
		}
	}else{
		if((b[b2]-max(a[b2],c[b2]))<=b[i]){
			
		}else{
			x[i]=0;
			if(a[i]>c[i]){
				a[i]=y[i];
				a1++;
				ans[j]-b[i];
				ans[j]+=a[i];
				if(a2==0){
			a2=i;
		}else if(a2>=a[i]){
			a2=i;
		}else{
			cout<<"";
		}
			}else{
				c[i]=z[i];
				c1++;
				ans[j]-b[i];
				ans[j]+=c[i];
				if(c2==0){
			c2=i;
		}else if(c2>=c[i]){
			c2=i;
		}else{
			cout<<"";
		}
			}
		}
		
	}
	
	}else{
		if(c1<mm){				
		z[i]=c[i];
		y[i]=0;
		x[i]=0;
		c1++;
		ans[j]+=c[i];
		if(c2==0){
			c2=i;
		}else if(c2>=c[i]){
			c2=i;
		}else{
			cout<<"";
		}
	}else{
		if((c[c2]-max(b[c2],a[c2]))<=c[i]){
			
		}else{
			x[i]=0;
			if(b[i]>a[i]){
				b[i]=y[i];
				b1++;
				ans[j]-c[i];
				ans[j]+=b[i];
				if(b2==0){
			b2=i;
		}else if(b2>=b[i]){
			b2=i;
		}else{
			cout<<"";
		}
			}else{
				a[i]=x[i];
				a1++;
				ans[j]-c[i];
				ans[j]+=a[i];
				if(a2==0){
			a2=i;
		}else if(a2>=a[i]){
			a2=i;
		}else{
			cout<<"";
		}
			}
		}
		
	}
	
		
	}
	cout<<ans[j]<<endl;
}

}
fclose(stdin);
fclose(stdout);
return 0;

}