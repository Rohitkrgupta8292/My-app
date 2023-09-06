#include <bits/stdc++.h>
using namespace std;

// Structure to represent a job
struct Job
{
    int deadline;
    int profit;
};

// Function to compare jobs based on profit (used for sorting)
bool compareJobs(const Job &a, const Job &b)
{
    return a.profit > b.profit;
}

// Function to find the maximum profit job sequence
void jobSequenceWithDeadline(Job arr[], int n)
{
    // Sort the jobs in decreasing order of profit
    sort(arr, arr + n, compareJobs);

    // Find the maximum deadline to determine the size of time slots array
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }

    // Initialize the time slots array
    int timeSlots[maxDeadline] = {0};
    int totalProfit = 0;

    // Fill the time slots with jobs
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline - 1; j >= 0; j--)
        {
            // Find the first available time slot for the job
            if (timeSlots[j] == 0)
            {
                timeSlots[j] = 1;             // Mark the time slot as occupied
                totalProfit += arr[i].profit; // Add the profit
                break;
            }
        }
    }

    // Output the maximum profit and the sequence of jobs
    cout << "Maximum Profit: " << totalProfit << endl;
    cout << "Job Sequence: ";
    for (int i = 0; i < maxDeadline; i++)
    {
        if (timeSlots[i] == 1)
        {
            cout << i + 1 << ",";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit and deadline for job " << i + 1 << ": ";
        cin >> arr[i].profit >> arr[i].deadline;
    }

    jobSequenceWithDeadline(arr, n);

    return 0;
}
