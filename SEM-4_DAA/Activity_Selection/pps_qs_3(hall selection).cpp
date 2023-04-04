/*
Question

Suppose we have a set S of activities (with the start-time and the finish time, as in the activity selection problem) that has to be scheduled among a 
large number of lecture halls, where any activity can take place in any lecture hall. The task is to schedule all the activities using as few lecture
halls. We call this problem as ‘Extended activity selection problem’. Given the set of activities and the detials of the lecture halls (say, l1, l2, ...lm), 
Design a greedy c++ code to determine which activity should use which lecture hall


Algorithm

Sort the activities by their finishing times in non-decreasing order.
Create an empty vector to hold the schedules for each lecture hall.
Loop through each activity in the sorted list:
a. If there are no schedules yet, schedule the activity in the first lecture hall and add the schedule to the vector.
b. Otherwise, loop through each lecture hall's schedule to see if the activity can be scheduled without overlapping with any other activities already scheduled in that lecture hall.
i. If the activity can be scheduled without overlapping with any activities, add the schedule to that lecture hall's schedule vector and break out of the loop.
ii. If the activity cannot be scheduled without overlapping with any activities in any of the lecture halls' schedules, create a new schedule for the activity in a new lecture hall and add the schedule to the vector of schedules.
Return the vector of schedules for each lecture hall.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int finish;
    int value;
    int hall; // added field to store the assigned hall
};

bool compare_activities(Activity a, Activity b) {
    return a.finish < b.finish;
}

bool compare_halls(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

vector<Activity> select_activities(vector<Activity> activities, vector<pair<int, int>>& halls) {
    vector<Activity> selected;
    sort(activities.begin(), activities.end(), compare_activities);
    sort(halls.begin(), halls.end(), compare_halls);

    for (Activity& activity : activities) {
        for (pair<int, int>& hall : halls) {
            if (hall.second <= activity.start) {
                activity.hall = hall.first;
                hall.second = activity.finish; // update hall's finish time
                break;
            }
        }
    }

    return activities;
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    cout << "Enter the start time, finish time, and value of each activity:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish >> activities[i].value;
        activities[i].hall = -1; // initialize hall as unassigned
    }

    int m;
    cout << "Enter the number of lecture halls: ";
    cin >> m;

    vector<pair<int, int>> halls(m);
    cout << "Enter the start time of each lecture hall:\n";
    for (int i = 0; i < m; i++) {
        int start_time;
        cin >> start_time;
        halls[i] = make_pair(i, start_time);
    }

    vector<Activity> selected = select_activities(activities, halls);

    cout << "Selected activities and their assigned halls:\n";
    for (Activity activity : selected) {
        cout << "<" << activity.start << "," << activity.finish << "," << activity.value << "> ";
        cout << "Hall " << activity.hall << "\n";
    }

    return 0;
}
