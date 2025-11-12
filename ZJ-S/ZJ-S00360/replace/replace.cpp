#include <bits/stdc++.h>
using namespace std;

struct ab
{
	int starta;
	int enda;
};

struct abchange
{
	ab from;
	ab to;
};

struct change
{
	string from;
	string to;
};

int n, m;
//bool specialB = true;

change replist[200000];
change purlist[200000];
int purstart[200000];
int purend[200000];
int anslist[200000];

int check(int repindex)
{
	change rep = replist[repindex];
	int fromborder[10000];
	int toborder[10000];
	int j = 0;
	for (int i = 1; i < rep.from.length(); i++)
	{
		while (true)
		{
			if (j == 0 || rep.from[j] == rep.from[i])
			{
				break;
			}	
			j = fromborder[j - 1];
		}	
		if (rep.from[i] == rep.from[j])
		{
			j++;
		}
		fromborder[i] = j;
	}
	
	j = 0;
	for (int i = 1; i < rep.to.length(); i++)
	{
		while (true)
		{
			if (j == 0 || rep.to[j] == rep.to[i])
			{
				break;
			}	
			j = toborder[j - 1];
		}	
		if (rep.to[i] == rep.to[j])
		{
			j++;
		}
		toborder[i] = j;
	}
	
	int book[10000];
	for (int i = 0; i < 10000; i++)
	{
		book[i] = 0;
	}
	for (int purindex = 0; purindex < m; purindex++)
	{
		j = 0;
		string A = rep.from;
		string B = purlist[purindex].from;
		for (int i = 0; i < B.length(); i++)
		{
			while (true)
			{
				if (j == 0 || A[j] == B[i])
				{
					break;
				}	
				j = fromborder[j - 1];
			}	
			if (B[i] == A[j])
			{
				j++;
			}
			if (j == A.length())
			{
				book[(i + 1) - A.length() + 1] = purindex;
				j = fromborder[j - 1];	
			}
		}
		
		j = 0;
		A = rep.to;
		B = purlist[purindex].to;
		for (int i = 0; i < B.length(); i++)
		{
			while (true)
			{
				if (j == 0 || A[j] == B[i])
				{
					break;
				}	
				j = toborder[j - 1];
			}	
			if (B[i] == A[j])
			{
				j++;
			}
			if (j == A.length())
			{
				if (book[(i + 1) - A.length() + 1] == purindex)
				{
					if ((i) - A.length() + 1 <= purstart[purindex] &&
					i >= purend[purindex])
						anslist[purindex]++;
					//cout << repindex << " " << purindex << "!!!" << endl;
				}
				
				j = toborder[j - 1];	
			}
		}
		
	}
	
	return 0;
}

//int B()
//{
//	abchange abreplist[200000];
//	abchange abpurlist[200000];
//	for (int i = 0; i < n; i++)
//	{
//		abreplist[i] = ;
//		abpurlist[i] = ;
//	}
//	vector <int>
//	
//	return 0;
//}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> replist[i].from >> replist[i].to;
		len += replist[i].from.length();
	}
	for (int i = 0; i < m; i++)
	{
		cin >> purlist[i].from >> purlist[i].to;
		purstart[i] = -1;
		for (int j = 0; j < purlist[i].from.length(); j++)
		{
			if (purlist[i].from[j] != purlist[i].to[j])
			{
				purend[i] = j;
				if (purstart[i] == -1) purstart[i] = j;
			}
		}
		//cout << purstart[i] << " " << purend[i] << endl;
	}
//	if (len >= 4000)
//	{
//		B();
//		return 0;
//	}
	for (int i = 0; i < n; i++)
	{
		check(i);
	}
	for (int i = 0; i < m; i++)
	{
		cout << anslist[i] <<endl;
	}
	return 0;	
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
