#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum=0,cnt=0,ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum=max(sum,a[i]);
		cnt+=a[i];
	}
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		    	if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))) ans++;
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		    for(int x=k+1;x<=n;x++)
		        if(a[i]+a[j]+a[k]+a[x]>2*max(a[i],max(a[j],max(a[k],a[x])))) ans++;
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		    for(int x=k+1;x<=n;x++)
		      for(int y=x+1;y<=n;y++)
		        if(a[i]+a[j]+a[k]+a[x]+a[y]>2*max(a[i],max(a[j],max(a[k],max(a[x],a[y]))))) ans++;
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		    for(int x=k+1;x<=n;x++)
		      for(int y=x+1;y<=n;y++)
		        for(int z=y+1;z<=n;z++)
		          if(a[i]+a[j]+a[k]+a[x]+a[y]>2*max(a[i],max(a[j],max(a[k],max(a[x],max(a[y],a[z])))))) ans++;
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		    for(int x=k+1;x<=n;x++)
		      for(int y=x+1;y<=n;y++)
		        for(int z=y+1;z<=n;z++)
		          for(int b=z+1;b<=n;b++)
		          if(a[i]+a[j]+a[k]+a[x]+a[y]+a[b]>2*max(a[i],max(a[j],max(a[k],max(a[x],max(a[y],max(a[z],a[b]))))))) ans++;
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		    for(int x=k+1;x<=n;x++)
		      for(int y=x+1;y<=n;y++)
		        for(int z=y+1;z<=n;z++)
		          for(int b=z+1;b<=n;b++)
		            for(int c=b+1;c<=n;c++)
		               if(a[i]+a[j]+a[k]+a[x]+a[y]+a[b]+a[c]>2*max(a[i],max(a[j],max(a[k],max(a[x],max(a[y],max(a[z],max(a[b],a[c])))))))) ans++;
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		    for(int x=k+1;x<=n;x++)
		      for(int y=x+1;y<=n;y++)
		        for(int z=y+1;z<=n;z++)
		          for(int b=z+1;b<=n;b++)
		            for(int c=b+1;c<=n;c++)
		              for(int d=c+1;d<=n;d++)
		               if(a[i]+a[j]+a[k]+a[x]+a[y]+a[b]+a[c]+a[d]>2*max(a[i],max(a[j],max(a[k],max(a[x],max(a[y],max(a[z],max(a[b],max(a[c],a[d]))))))))) ans++;
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		    for(int x=k+1;x<=n;x++)
		      for(int y=x+1;y<=n;y++)
		        for(int z=y+1;z<=n;z++)
		          for(int b=z+1;b<=n;b++)
		            for(int c=b+1;c<=n;c++)
		              for(int d=c+1;d<=n;d++)
		                for(int e=d+1;e<=n;e++)
		                  if(a[i]+a[j]+a[k]+a[x]+a[y]+a[b]+a[c]+a[d]+a[e]>2*max(a[i],max(a[j],max(a[k],max(a[x],max(a[y],max(a[z],max(a[b],max(a[c],max(a[d],a[e])))))))))) ans++;
	cout<<ans;
	return 0;
}
