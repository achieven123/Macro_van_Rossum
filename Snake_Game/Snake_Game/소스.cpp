#include <stdio.h>

int main(){

	while (1)
	{
		 int p, i;
		 double sum = 0, cnt = 0;
		 double result;

		 
		scanf("%d", &p);
		for (i = 0; i < p; i++)
		{
			int s;
			

			scanf("%d", &s);
			if (s<101 && s>-1)
			{
				sum += s;
				cnt += 1;
				
			}
		}
		result = sum / cnt;

		printf("%.2lf\n", result);

		if (p == 0)
		{
			break;
		}
	}

}