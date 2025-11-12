#include<stdio.h>
#include<string.h>
#include<unordered_map>
#include<vector>
namespace mns
{
	#define hh unsigned long long
	char s1[2500000],s2[2500000];
	struct PS
	{
		hh ph,sh;
		int ps,ss;
	};
	hh hash(char *s,int len)
	{
		int i;
		hh h=0;
		for(i=0;i<len;++i)
		{
			h=h*131+s[i];
		}
		return h;
	}
	hh dhash(char *s1,char *s2,int len)
	{
		return hash(s1,len)*998244353+hash(s2,len);
	}
	std::unordered_map<hh,std::vector<PS>> map;
	int main()
	{
		int n,q,i,j,s,e,ans;
		hh x;
		PS r;
		scanf("%d%d",&n,&q);
		for(i=0;i<n;++i)
		{
			scanf("%s%s",s1,s2);
			j=0;
			while(s1[j]==s2[j])
			{
				j++;
			}
			s=j;
			j=e=strlen(s1)-1;
			while(s1[j]==s2[j])
			{
				j--;
			}
			x=dhash(s1+s,s2+s,j-s+1);
			r.ph=hash(s1,s);
			r.sh=hash(s1+j+1,e-j);
			r.ps=s;
			r.ss=e-j;
			map[x].push_back(r);
		}
		for(i=0;i<q;++i)
		{
			ans=0;
			scanf("%s%s",s1,s2);
			if(strlen(s1)!=strlen(s2))
			{
				printf("0\n");
				continue;
			}
			j=0;
			while(s1[j]==s2[j])
			{
				j++;
			}
			s=j;
			j=e=strlen(s1)-1;
			while(s1[j]==s2[j])
			{
				j--;
			}
			x=dhash(s1+s,s2+s,j-s+1);
			if(map.count(x)!=0)
			{
				for(PS k:map[x])
				{
					if(hash(s1+s-k.ps,k.ps)==k.ph&&hash(s1+j+1,k.ss)==k.sh)
					{
						ans++;
					}
				}
			}
			printf("%d\n",ans);
		}
		return 0;
	}
};
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	mns::main();
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
