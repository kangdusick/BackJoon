#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

int* Bsearch(int* dataList, int ave1, int size)
{
	int left = 0;
	int right = size - 1;
	int mid = left + (right - left) / 2;
	int ave1LR[4];
	while (true)
	{
		if (dataList[mid] == ave1)
		{
			ave1LR[0] = ave1;
			ave1LR[1] = ave1;
			ave1LR[2] = left;
			ave1LR[3] = right;
			break;
		}
		else if (right - left == 1 || left == right)
		{
			ave1LR[0] = dataList[left];
			ave1LR[1] = dataList[right];
			ave1LR[2] = left;
			ave1LR[3] = right;
			break;
		}
		else if (dataList[mid] > ave1)
		{
			right = mid - 1;
			mid = left + (right - left) / 2;
		}
		else if (dataList[mid] < ave1)
		{
			left = mid + 1;
			mid = left + (right - left) / 2;
		}
	}
	return ave1LR;
}


int main()
{
	int n = 0;
	int m = 0;
	int i = 0;
	int k = 0;

	scanf("%d", &n);
	scanf("%d", &m);
	int* data = new int[n];
	int** chois = new int* [n];
	int* ansList = new int[n * 4];
	for (i = 0; i < n * 4; i++)
	{
		ansList[i] = -1;
	}
	int anscount = 0;
	for (i = 0; i < n; i++)
	{
		*(chois + i) = new int[7];
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", data + i);
	}
	sort(data, data + n);

	for (k = 0; k < n; k++)
	{
		chois[k][0] = data[k];
		int* tempdata0 = new int[n - 1];
		int j = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (j == k)
			{
				j++;
				i--;
				continue;
			}
			tempdata0[i] = data[j];
			j++;
		}

		int ave1 = (m - chois[k][0]) / 2;
		int a[4];
		int* aa = Bsearch(tempdata0, ave1, n - 1);
		a[0] = aa[0];
		a[1] = aa[1];
		a[2] = aa[2];
		a[3] = aa[3];
		chois[k][1] = a[0];
		chois[k][2] = a[1];

		int* tempdata1 = new int[n - 2];
		j = 0;
		for (i = 0; i < n - 2; i++)
		{
			if (j == a[2])
			{
				j++;
				i--;
				continue;
			}
			tempdata1[i] = tempdata0[j];
			j++;
		}
		int ave2 = m - chois[k][0] - chois[k][1];
		int* c = Bsearch(tempdata1, ave2, n - 2);
		chois[k][3] = c[0];
		chois[k][4] = c[1];

		int* tempdata2 = new int[n - 2];
		j = 0;
		for (i = 0; i < n - 2; i++)
		{
			if (j == a[3])
			{
				j++;
				i--;
				continue;
			}
			tempdata2[i] = tempdata0[j];
			j++;
		}
		int ave3 = m - chois[k][0] - chois[k][2];
		int* d = Bsearch(tempdata2, ave3, n - 2);
		chois[k][5] = d[0];
		chois[k][6] = d[1];


		ansList[anscount++] = chois[k][0] + chois[k][1] + chois[k][3];
		if (ansList[anscount - 1] > m || chois[k][1] == chois[k][3]) anscount--;
		ansList[anscount++] = chois[k][0] + chois[k][1] + chois[k][4];
		if (ansList[anscount - 1] > m || chois[k][1] == chois[k][4]) anscount--;
		ansList[anscount++] = chois[k][0] + chois[k][2] + chois[k][5];
		if (ansList[anscount - 1] > m || chois[k][2] == chois[k][5]) anscount--;
		ansList[anscount++] = chois[k][0] + chois[k][2] + chois[k][6];
		if (ansList[anscount - 1] > m || chois[k][2] == chois[k][6])
		{
			anscount--;
			ansList[anscount] = -1;
		}
	}
	int* solutionList = new int[anscount];
	for (i = 0; i < anscount; i++)
	{
		solutionList[i] = ansList[i];
	}
	sort(solutionList, solutionList + anscount);
	printf("%d\n", solutionList[anscount - 1]);

	for (i = 0; i < anscount; i++)
	{
		printf("sol%d: %d\n", i, solutionList[i]);
	}


	for (int i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");


	for (k = 0; k < n; k++)
	{
		printf("%d ", chois[k][0]);
		printf("%d ", chois[k][1]);
		printf("%d ", chois[k][2]);
		printf("%d ", chois[k][3]);
		printf("%d ", chois[k][4]);
		printf("%d ", chois[k][5]);
		printf("%d \n", chois[k][6]);
	}

	for (k = 0; k < n; k++)
	{
		printf("%d¹ø¤Š:\n", k);
		printf("##1: %d, %d, %d = %d ", chois[k][0], chois[k][1], chois[k][3], chois[k][0] + chois[k][1] + chois[k][3]);
		printf("##2: %d, %d, %d = %d ", chois[k][0], chois[k][1], chois[k][4], chois[k][0] + chois[k][1] + chois[k][4]);
		printf("##3: %d, %d, %d = %d ", chois[k][0], chois[k][2], chois[k][5], chois[k][0] + chois[k][2] + chois[k][5]);
		printf("##4: %d, %d, %d = %d \n", chois[k][0], chois[k][2], chois[k][6], chois[k][0] + chois[k][2] + chois[k][6]);
	}

	return 0;
}