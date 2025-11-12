#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

vector<pair<int,int> > in[4];

int tot[4];

int a[4][100005];


int where[100005];
void outp()
{int ans=0;
	
			for(int i=0;i<3;i++){
		for(int ii=0;ii<tot[i];ii++){cout<<in[i][ii].first<<' ';ans+=a[where[in[i][ii].second]][in[i][ii].second];
		}
		cout<<endl;
		}
		cout<<"SUM="<<ans<<endl<<tot[0]<<' '<<in[0].size()<<' '<<tot[1]<<' '<<in[1].size()<<' '<<tot[2]<<' '<<in[2].size()<<' '<<endl;
}
int SUM()
{
	int ans=0;
	
			for(int i=0;i<3;i++){
		for(int ii=0;ii<tot[i];ii++)ans+=a[where[in[i][ii].second]][in[i][ii].second];
		}return ans;
		
}
int max3(int a,int b,int c)
{
	if(a>=max(b,c))return 0;
	if(b>=max(a,c))return 1;
	if(c>=max(a,b))return 2;
	
}
int max3dif(int a,int b,int c)
{
	if(a>=max(b,c))return max(b,c);
	if(b>=max(a,c))return max(a,c);
	if(c>=max(a,b))return max(a,b);
	
}
int max3dif_index(int a,int b,int c)
{
	if(a>=max(b,c))return max(b,c)==b?1:2;
	if(b>=max(a,c))return max(a,c)==a?0:2;
	if(c>=max(a,b))return max(a,b)==a?0:1;
	
}
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a.first>b.first;
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(tot,0,sizeof(tot));
		memset(a,0,sizeof(a));
		memset(where,0,sizeof(where));
		for(int i=0;i<=3;i++)in[i].clear();
		int n;
		cin>>n;
		
		//for(int i=0;i<3;i++)in[i].resize(n+5);
		
		for(int i=0;i<n;i++)cin>>a[0][i]>>a[1][i]>>a[2][i];
		//outp();
		for(int i=0;i<n;i++)
		{
			in[max3(a[0][i],a[1][i],a[2][i])].push_back({a[max3(a[0][i],a[1][i],a[2][i])][i]-max3dif(a[0][i],a[1][i],a[2][i]),i});//in[给出的最大分的club滑档后减少的分]{给出的最高分,i}
			tot[max3(a[0][i],a[1][i],a[2][i])]++;
			where[i]=max3(a[0][i],a[1][i],a[2][i]);
		}
		//outp();
			for(int i=0;i<3;i++){
				sort(in[i].begin(),in[i].end(),cmp);}
			//outp();
			bool check_ac=1;
			
			for(int _=5;_>=0;_--)
			{
				if(check_ac&&_!=5) {cout<<SUM()<<endl;break;	}
				check_ac=1;
			for(int i=0;i<3;i++){check_ac=0;
				sort(in[i].begin(),in[i].end(),cmp);
				
				if(tot[i]>n/2)
				//cout<<_<<i<<endl;
				for(int ii=tot[i]-1;ii>=n/2;ii--)
				{
					check_ac=1;
					int now_i=in[i][ii].second;
					
					
					
					//cout<<in[i][ii].second<<" -"<<in[i][ii].first<<"->"<<max3dif_index(a[0][now_i],a[1][now_i],a[2][now_i])<<'/';
					//cout<<a[max3(a[0][now_i],a[1][now_i],a[2][i])][now_i]-max3dif(a[0][now_i],a[1][now_i],a[2][now_i])<<endl;
					a[i][now_i]=0;//不要你
					 
					 in[i].erase(in[i].end());
					 tot[i]--;					 
					in[max3(a[0][now_i],a[1][now_i],a[2][now_i])].push_back({a[max3(a[0][now_i],a[1][now_i],a[2][now_i])][now_i]-max3dif(a[0][now_i],a[1][now_i],a[2][now_i]),now_i});//in[给出的最大分的club滑档后减少的分]{给出的最高分,i}
					tot[max3(a[0][now_i],a[1][now_i],a[2][now_i])]++;
					
					where[now_i]=max3(a[0][now_i],a[1][now_i],a[2][now_i]);
					
				}
				//cout<<endl;
			
			}
			
			//outp();
			
				if(_==0)cout<<SUM()<<endl;
			}
			

	}
	return 0;
}
