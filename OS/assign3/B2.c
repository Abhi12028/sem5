#include <stdio.h>
#include<string.h>


struct Input
{
	char pname[10];
	int bt, at, ct, tbt, p; //tbt = temp Burst time
} tab[5];

struct Sequence
{
	int start, end;
	char pname[10];
} seq[100], seq1[20];

int finish, time, n, k, prev, q;

void getinput()
{
	int i;
	printf("\nEnter No.of Processes:");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Process name:");
		scanf("%s", tab[i].pname);
		printf("Burst time:");
		scanf("%d", &tab[i].bt);
		printf("Arrival time:");
		scanf("%d", &tab[i].at);
		printf("Enter priority: ");
		scanf("%d", &tab[i].p);

		tab[i].tbt = tab[i].bt;
	}
}
void printinput()
{
	int i;

	printf("\nProcess\tBT\tAT\tpriority");
	for (i = 0; i < n; i++)
		printf("\n%s\t%d\t%d\t%d", tab[i].pname, tab[i].tbt, tab[i].at, tab[i].p);
	//getch();
}

void bubble()
{
	struct Input t;
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < (n - 1) - i; j++)
			if (tab[j].at > tab[j + 1].at)
			{
				t = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = t;
			}
}
int getmin(int t)
{
	int i, mini, min = 99;
	for (i = 0; i < n; i++)
		if (tab[i].at <= t && tab[i].tbt != 0 && tab[i].p < min)
		{
			min = tab[i].p;
			mini = i;
		}
	return mini;
}

void printoutput()
{
	int i;
	float AvgTAT = 0, AvgWT = 0;
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT");
	for (i = 0; i < n; i++)
	{
		printf("\n%s\t%d\t%d\t%d\t%d\t%d", tab[i].pname,
			   tab[i].at,
			   tab[i].bt,
			   tab[i].ct,
			   tab[i].ct - tab[i].at,
			   tab[i].ct - tab[i].at - tab[i].bt);
		AvgTAT += tab[i].ct - tab[i].at;
		AvgWT += tab[i].ct - tab[i].at - tab[i].bt;
	}
	AvgTAT /= n;
	AvgWT /= n;
	printf("\nAverage TAT = %f", AvgTAT);
	printf("\nAverage WT = %f", AvgWT);
	//getch();
}

int arrived(int t)
{
	int i;
	for (i = 0; i < n; i++)
		if (tab[i].at <= t && tab[i].tbt != 0)
			return 1;
	return 0;
}

void processinput()
{
	int i = 0, j;
	finish = k = 0;
	while (finish != n)
	{
		if (arrived(time))
		{
			i = getmin(time);
			for (j = 0; j < tab[i].bt; j++)
			{
				time++;
				tab[i].tbt--;
				printinput();
				prev = time;
				tab[i].ct = time;
				if (tab[i].tbt == 0)
				{
					finish++;
					break;
				}
			}
		}
		else
		{
			time++;
			prev = time;
		}
	}
}
void main()
{
	int i;
	getinput();
	printf("\nEntered data-: ");
	printinput();
	bubble();
	printf("\nData after sorting according to arrival time-: ");
	printinput();
	processinput();

	printoutput();

	//ganttchart();
}

