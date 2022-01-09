#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "Enter the num. of proesses : ";
	cin >> n;
	int bt[25], pr[25], index[25], tat[25], wt[25];
	
	cout << "Enter the burst time of processes : " << endl;
	for(int i = 0; i < n; i++)
	{
		cout << "P" << i << endl;
		cout << "Burst Time : ";
		cin >> bt[i];
		cout << "Priority : ";
		cin >> pr[i];
		index[i] = i;
	}
	
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < n-1; j++)
		{
			if(pr[i] < pr[j])
			{
				int temp = pr[i];
				pr[i] = pr[j];
				pr[j] = temp;
				
				int temp1 = bt[i];
				bt[i] = bt[j];
				bt[j] = temp1;
				
				int temp2 = index[i];
				index[i] = index[j];
				index[j] = temp2;
			}
		}
	}
	
	wt[0] = 0;
	for(int i = 0; i < n; i++)
	{
		wt[i] = 0;
		for(int j = 0; j < i; j++)
		{
			wt[i] = wt[i] + bt[j];
		}
	}
	
	float avg_wt = 0, avg_tat = 0;
	for(int i = 0; i < n; i++)
	{
		tat[i] = wt[i] + bt[i];
		avg_wt = avg_wt + wt[i];
		avg_tat = avg_tat + tat[i];
	}
	
	cout << "Process ID \t Priority\t Burst time\t Waiting Time\t Turnaround time\t" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << "P" << index[i] << "\t\t" << pr[i] << "\t\t" << bt[i] << " \t\t" << wt[i] <<"\t\t" << tat[i] << endl;
	}
	cout << "\n Average Waiting Time : " << (avg_wt/n) << endl;
	cout << "\n Average Turn Around Time : " << (avg_tat/n) << endl;
	
	return 0;
}
