#include<bits/stdc++.h> 
using namespace std;
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   int n,m,a[10]={},c=1,r=1;
   cin>>n>>m>>a[10];
   if (n==1){
   
   if(a[0]<a[1]){
   	r+=r;
   	a[1]=a[0];
   }
   
   else if(a[1]<a[2]){
   	r+=r;
   	a[2]=a[1];
   }
    else if(a[2]<a[3]){
   	r+=r;
   	a[3]=a[2];
   }
    else if(a[3]<a[4]){
   	r+=r;
   	a[4]=a[3];
   }
    else if(a[4]<a[5]){
   	r+=r;
   	a[5]=a[4];
   }
    else if(a[5]<a[6]){
   r+=r;
   	a[6]=a[5];
   } else if(a[6]<a[7]){
   	r+=r;
   	a[7]=a[6];
   } else if(a[7]<a[8]){
   	r+=r;
   	a[8]=a[7];
   }
   else if(a[8]<a[9]){
   	r+=r;
   	
}
  
 cout<<n<<" "<<r;
}
   else if (m==1,n<=10){
   
   if(a[0]<a[1]){
   	c+=c;
   	a[1]=a[0];
   }
   else if(a[1]<a[2]){
   	c+=c;
   	a[2]=a[1];
   }
    else if(a[2]<a[3]){
   	r+=r;
   	a[3]=a[2];
   }
    else if(a[3]<a[4]){
   	c+=c;
   	a[4]=a[3];
   }
    else if(a[4]<a[5]){
   	c+=c;
   	a[5]=a[4];
   }
    else if(a[5]<a[6]){
   c+=c;
   	a[6]=a[5];
   } else if(a[6]<a[7]){
   	c+=c;
   	a[7]=a[6];
   } else if(a[7]<a[8]){
   	c+=c;
   	a[8]=a[7];
   }
   else if(a[8]<a[9]){
   	c+=c;
   	a[9]=a[8];
}

 
 cout<<c<<" "<<m;
}
   
   return 0; 
}
