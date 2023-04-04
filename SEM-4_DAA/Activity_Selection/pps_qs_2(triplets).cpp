/*
Question

Let S = {a1, a2, ..., an} be the set of activities. Each activity ai has the start-time(si), finish-time (fi) and a value (vi). 
Every ai is associated with a triplet < si,fi, vi >. 
Any two activities ai =< si,fi, vi > , aj =<sj, fj, vj > are compatible if si >= fj or sj >= fi. 
Design an c++ code to choose a set A of compatible activities such that ak∈Avk is maximum.

Algorithm

1. Define a struct Activity that has start time, finish time, and value fields.
2. Define a function compare_activities that takes two Activity objects as input and returns true if the finish time of the first activity is less than the finish time of the second activity.
3. Define a function select_activities that takes a vector of Activity objects as input and returns a vector of selected Activity objects.
4. Sort the input vector of Activity objects in non-decreasing order of finish times using the compare_activities function.
5. Initialize an empty vector called selected to hold the selected Activity objects.
6. Add the first Activity object from the sorted input vector to the selected vector.
7. Set a variable called last_selected to 0 to hold the index of the last selected Activity object.
8. Loop through the remaining Activity objects in the sorted input vector from the second one to the last one:
   a. If the start time of the current Activity object is greater than or equal to the finish time of the last selected Activity object:
      i. Add the current Activity object to the selected vector.
      ii. Set last_selected to the index of the current Activity object.
9. Return the selected vector of Activity objects.
10. In the main function, prompt the user to enter the number of activities.
11. Initialize a vector called activities to hold the Activity objects input by the user.
12. Prompt the user to enter the start time, finish time, and value of each activity and store the input in the corresponding fields of the Activity objects in the activities vector.
13. Call the select_activities function with the activities vector as input and store the result in a vector called selected.
14. Output the selected Activity objects in the format "<start_time,finish_time,value>".
15. Exit the program.

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int finish;
    int value;
};

bool compare_activities(Activity a, Activity b) {
    return a.finish < b.finish;
}

vector<Activity> select_activities(vector<Activity> activities) {
    vector<Activity> selected;
    sort(activities.begin(), activities.end(), compare_activities);

    selected.push_back(activities[0]);
    int last_selected = 0;

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= activities[last_selected].finish) {
            selected.push_back(activities[i]);
            last_selected = i;
        }
    }

    return selected;
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    cout << "Enter the start time, finish time, and value of each activity:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish >> activities[i].value;
    }

    vector<Activity> selected = select_activities(activities);

    cout << "Selected activities: ";
    for (Activity activity : selected) {
        cout << "<" << activity.start << "," << activity.finish << "," << activity.value << "> ";
    }
    cout << endl;

    return 0;
}
