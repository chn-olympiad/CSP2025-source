#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string zfc;
    int num[1000005];
    int a=0;
    cin>>zfc;
    for(int i=0;i<=zfc.length()-1;i++)
    {
        if(zfc[i]=='0'&&zfc[i]=='1'&&zfc[i]=='2'&&zfc[i]=='3'&&zfc[i]=='4'&&zfc[i]=='5'&&zfc[i]=='6'&&zfc[i]=='7'&&zfc[i]=='8'&&zfc[i]=='9')
        {
            num[a]=zfc[i];
            a++;
        }
        for(int j=0;j<=a;j++)
        {	
        	int lt;
            for(int z=0;z<=a;z++)
            {
                lt=0;
                lt=max(lt,num[z]);
            }
            cout<<lt;
            for(int y=0;y<=a;y++)
			{
				if(num[y]==lt)
				{
					num[y]-=lt;
				}
			}
        }

    }

    return 0;
}
