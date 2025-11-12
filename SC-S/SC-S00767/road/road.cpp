#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct road
{
	long int u, v, w, c, j;
};

int cmp(const void *a, const void *b)
{
	return (*(struct road *)(a)).w + (*(struct road *)(a)).c - (*(struct road *)(b)).w - 
		(*(struct road *)(b)).c;
}

int main()
{
	FILE *in, *out;
	in = fopen("road.in", "r");
	out = fopen("road.out", "w");
	//in = stdin; out = stdout;
	long int n, m, k, u, v, w, c, i, j;
	long int *root, *prefix, top,cnt;
	unsigned char *book;
	struct road *r;
	
	fscanf(in, "%ld %ld %ld", &n, &m, &k);
	root = (long int *) malloc(sizeof(long int) * (n + k));
	prefix = (long int *) malloc(sizeof(long int) * (n + k));
	book = (unsigned char *) malloc(sizeof(unsigned char) * k);
	r = (struct road *) malloc(sizeof(struct road) * (n + n * k));

	for (i = 0; i < n + k; i++)
	{
		root[i] = i;
		prefix[i] = -1;
	}
	for (i = 0; i < k; i++) book[i] = 0;
	top = 0;
	cnt = 0;

	for (i = 0; i < m; i++)
	{
		fscanf(in, "%ld %ld %ld", &u, &v, &w);
		u--; v--;
		if (u != v) 
		{
			r[top].u = u;
			r[top].v = v;
			r[top].w = w;
			r[top].c = 0;
			r[top].j = -1;
			top++;
		}
	}
	for (i = 0; i < k; i++)
	{
		fscanf(in, "%ld", &c);
		for (j = 0; j < n; j++)
		{
			fscanf(in, "%ld", &w);
			r[top].u = i + n;
			r[top].v = j;
			r[top].w = w;
			r[top].c = c;
			r[top].j = i;
			top++;

		}
	}

	qsort(r, top, sizeof(struct road), cmp);
	j = 0;
	for (i = 0; i < top && j < n; i++)
	{
		//fprintf(out, "%ld %ld %ld %ld %ld\n", r[i].u, r[i].v, r[i].w, r[i].c, r[i].j);
		if (root[r[i].u] != root[r[i].v])
		{
			if (root[r[i].v] == r[i].v)
			{
				root[r[i].v] = root[r[i].u];
				prefix[r[i].v] = r[i].u;
			}
			else
			{
				root[r[i].u] = root[r[i].v];
				prefix[r[i].u] = r[i].v;
			}
			if (r[i].j == -1)
			{
				cnt += r[i].w;
				j++;
			}
			else if (book[r[i].j] == 1)
			{
				cnt += r[i].w;
			}
			else
			{
				cnt += r[i].w + r[i].c;
				book[r[i].j] = 1;
			}
			
		}
	}
/*
	for (i = 0; i < n + k; i++)
	{
		fprintf(out, "%ld:%ld\n", i, prefix[i]);
	}
*/
	fprintf(out, "%ld\n", cnt);

	free(root);
	free(prefix);
	free(r);
	free(book);

	fclose(in);
	fclose(out);	
	return 0;
}