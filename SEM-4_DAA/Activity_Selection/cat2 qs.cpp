/*
Question

Given a set of courses S§ = {C1,Cy,...,Cr}, where each C; is represented by a pair of numbers ,
C; =< start — No., End — No. >. The courses in S are the courses in which students are interested to
take if offered by the school. Cy =< 1234,1267 > means that the students with roll numbers 1234,1235,1236,...1266, 1267 are interested in taking the course. 
Assume that there are enough slots to offer all the n courses. 
Given S and a positive integer k, design a greedy based c++ code to identify the courses that can be offered to the students in such a way that 
(i) no course can have more than k students. (ii) one student can take only one course (iii) Maximum number of students are offered with the courses. 


Algorithm

Read in the number of courses n and the maximum number of students per course k.
Read in the starting and ending roll numbers for each course and store them in a vector of Course structs.
Sort the vector of courses by their ending roll number in ascending order.
Initialize a counter cnt for the number of assigned students and an array chosen of booleans to keep track of which courses have been chosen.
For each course in the sorted vector of courses, iterate through the vector of courses and choose the course if it is not already chosen, its starting roll number is after the current roll number, and its ending roll number is at least as large as the ending roll number of the current course. Update the current roll number to the ending roll number of the chosen course, mark the chosen course as chosen in the chosen array, and increment the counter cnt for the number of assigned students.
If the counter cnt reaches the maximum number of students per course k, stop assigning students and break out of the loop.
Output the number of assigned students cnt.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Course {
    int start, end;
};

// Comparator function to sort courses by their ending roll number in ascending order
bool cmp(Course a, Course b) {
    return a.end < b.end;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Course> courses(n);
    for (int i = 0; i < n; i++) {
        cin >> courses[i].start >> courses[i].end;
    }

    // Sort courses by their ending roll number in ascending order
    sort(courses.begin(), courses.end(), cmp);

    int cnt = 0; // Counter for number of assigned students
    vector<bool> chosen(n, false); // Array to keep track of which courses are chosen
    for (int i = 0; i < n; i++) {
        int cur = 0; // Current roll number of the last assigned student
        for (int j = 0; j < n; j++) {
            // Choose the course if it is not already chosen, its starting roll number is after the current roll number,
            // and its ending roll number is at least as large as the ending roll number of the current course
            if (!chosen[j] && courses[j].start > cur && courses[j].end >= courses[i].end) {
                cur = courses[j].end; // Update the current roll number
                chosen[j] = true; // Mark the course as chosen
                cnt++; // Increment the counter for assigned students
            }
            if (cnt == k) { // Stop assigning students if we have reached the limit of k
                break;
            }
        }
        if (cnt == k) { // Stop assigning students if we have reached the limit of k
            break;
        }
    }

    cout << cnt << endl; // Output the number of assigned students
    return 0;
}
