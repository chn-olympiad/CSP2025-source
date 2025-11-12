#include <bits/stdc++.h>
using namespace std;

const int NN=200005,LL=2500005;
string s1[NN],s2[NN],t1,t2;
int n,q,p1[LL],p2[LL];

int text(int x)
{
	memset(p1,0,sizeof(p1));
	memset(p2,0,sizeof(p2));
	
	int num=0,np1=0,np2=0;
	
	for(int i=1;i<=t1.size();i++)
	{
		int j=i,k=1;//j表是目前所在t1的下标 
		
		while(t1[j]==s1[x][k])
		{
			j++;k++;  
			if(k>s1[x].size()) break;
		}
	//	if(x==1) cout<<"fu "<<k<<endl;
		
//		if(x==3) cout<<"fuck "<<k<<endl;
		
		if(k>=s1[x].size()) 
		{
		//	if(x==1) cout<<"jin "<<x<<" "<<k<<endl;
			np1++;
			p1[np1]=i;
		}
	}
	
	for(int i=1;i<=t2.size();i++)
	{
		int j=i,k=1;//j表是目前所在t1的下标 
		
		while(t2[j]==s2[x][k])
		{
			j++;k++;  
			if(k>s2[x].size()) break;
		}
	//	if(x==1) cout<<"fu "<<k<<endl;
		
	//	if(x==3) cout<<"fuck "<<k<<endl;
		
		if(k>=s2[x].size()) 
		{
			//if(x==1) cout<<"jin "<<x<<" "<<k<<endl;
			np2++;
			p2[np2]=i;
		}
	}
	
	for(int i=1;i<=np1;i++)
		for(int j=1;j<=np2;j++)
			if(p1[i]==p2[j])
				num++;
	
//	if(x==1) cout<<"hhahh "<<np1<<' '<<np2<<' '<<endl;
	
	return num;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		s1[i]=' '+s1[i];
		s2[i]=' '+s2[i];
	}
		
	
	for(int i=1;i<=q;i++)
		cin>>t1>>t2;
	t1=' '+t1;
	t2=' '+t2;
	
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=text(i);
	
	cout<<ans<<endl;
	//cout<<t1<<endl<<t2<<endl;
	
	return 0;
}
