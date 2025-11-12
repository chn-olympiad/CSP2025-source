#include<bits/stdc++.h>
using namespace std;
int a[5030010],d[5030010],h[200010][3];
char b[5030010],c[5030010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,p,wz=1;
	cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
    	string e,f;
    	cin>>e>>f;
    	int sl=strlen(b);
    	for(int i=1;i<=sl-1;i++)
    	{
        a[wz]=e[i-1]-'0';
        b[wz]=f[i-1]-'0';
        wz++;
		}
		h[i][2]=wz-1;
		wz++;
		h[i+1][1]=wz;
	}
      if(p==1){
      	cout<<0;
      	return 0;
	  }
    	for(int o=1;o<=p;o++)
    	{
    		int ans=0;
    		cin>>b>>c;
    	int q=0,m=0,w=1,pd=1;
    	int sl=strlen(b);
    	for(int i=1;i<=sl;i++)
    	{
         if(m==0&&b[i]!=c[i]) q=i;
         if(b[i]!=c[i]) m=i;
		}
		for(int i=1;i<=n;i++)
		{
			pd=1;
           for(int j=1;j<=sl-h[i][2]+h[i][1];j++)
           {
           	for(int k=j;k<=sl-j-h[i][2]+h[i][1];k++)
           	{
           		if(a[k]==b[j]-'0'&&d[k]==c[j]-'0')
           		{
           			continue;
				   }
				   pd=0;
			   }
			   if(pd=1&&sl-j-h[i][2]+h[i][1]>=m) ans++;
		   }
		}
	cout<<ans<<endl;
		}
	return 0;
}