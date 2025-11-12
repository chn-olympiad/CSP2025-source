#include<bits/stdc++.h>
using namespace std;
int N,m,a[10001][1000],b[1000],ui[10][4],h=0,g[100],f[100],y[16],q[100],e;
int main(){
   freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t,n,s=0,l=0,po=0;
    cin>>t>>n;
    for(int yu=1;yu<=t;yu++){
    for(int j=1;j<=n;j++){
    cin>>a[j][1]>>a[j][2]>>a[j][3];
    for(int i=1;i<=3;i++)   ui[j][i]=i;
    if(a[j][1]<a[j][2])  swap(ui[j][1],ui[j][2]);
    if(a[j][1]<a[j][3])  swap(ui[j][1],ui[j][3]);
 	if(a[j][2]<a[j][3])  swap(ui[j][2],ui[j][3]);
	g[ui[j][1]]++;}
    e=n/2;
  for(int i=1;i<=n;i++){
  	y[++h]=a[i][ui[i][1]]-a[i][ui[i][2]];
  	y[++h]=a[i][ui[i][2]]-a[i][ui[i][3]];
  }
 int u=0;
  while(!u){
  u=1;N=0;
  for(int io=1;io<=3;io++) 
    if(g[io]>e) { u=0;
    int max=-1;
for(int i=1;i<=h;i++){
    if(i%2==1)  if(y[i]>max)  {max=y[i];m=i;}	
	if(i%2==0)  if(y[i]>max)  {max=y[i];m=i;}}
	y[m]=0;
	f[m]=1;swap(ui[m/2][2-m%2],ui[m/2][3-m%2]);m=m%2;
  	for(int io=1;io<=3;io++) {
    if(g[io]>e)  N=1;
    if(!N)  g[2-m]++;g[3-m]--;}
	  g[2-m]--;g[3-m]++;
	  
  }
    
    
  }
 for(int j=1;j<=n;j++)
 s+=a[j][ui[j][1]];
   cout<<s;}
	return 0;
}